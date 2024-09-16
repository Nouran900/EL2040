import speech_recognition as sr
from gtts import gTTS
from playsound import playsound
import webbrowser
from datetime import datetime
import requests
import time
import threading
import sounddevice
# Define your jokes and weather API here
API_KEY = '824af57f414376afe999df6768b1f32f'
BASE_URL = "http://api.openweathermap.org/data/2.5/weather?"

# Define your functions here
def set_reminder(reminder_text, reminder_time):
    if len(reminder_time) == 4 and reminder_time.isdigit():
        reminder_time = reminder_time[:2] + ":" + reminder_time[2:]
    now = datetime.now()
    reminder_datetime = datetime.strptime(reminder_time, "%H:%M").time()
    print(reminder_datetime)
    reminder_datetime = datetime.combine(now.date(), reminder_datetime)
    if reminder_datetime > now:
        time_diff = reminder_datetime - now
        print(f"Reminder set for {reminder_datetime}. Waiting for {time_diff}.")
        def wait_and_remind():
            time.sleep(time_diff.total_seconds())
            tts = gTTS(text=f"Reminder: {reminder_text}", lang='en', slow=False)
            tts.save("reminder.mp3")
            playsound("reminder.mp3")
        threading.Thread(target=wait_and_remind).start()
    else:
        print("Reminder time has already passed.")

def fetch_joke():
    try:
        response = requests.get("https://official-joke-api.appspot.com/random_joke")
        joke_data = response.json()
        joke = f"{joke_data['setup']} ... {joke_data['punchline']}"
        return joke
    except requests.exceptions.RequestException:
        return "Sorry, I couldn't fetch a joke right now."

def get_weather(city_name):
    complete_url = BASE_URL + "q=" + city_name + "&appid=" + API_KEY + "&units=metric"
    response = requests.get(complete_url)
    data = response.json()
    if data.get("cod") == 200:
        main = data.get("main", {})
        weather_description = data.get("weather", [{}])[0].get("description", "No description available")
        temperature = main.get("temp", "No temperature data")
        return f"The current temperature in {city_name} is {temperature}°C with {weather_description}."
    else:
        return f"Sorry, I couldn't retrieve the weather. Error: {data.get('message', 'Unknown error')}"

def listen_for_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source, duration=2)
        print("Listening for trigger word...")
        audio = recognizer.listen(source)
    try:
        text = recognizer.recognize_google(audio).lower()
        if "alexa" in text:
           tts = gTTS(text="Hello Nouran, how can I help you today?", lang='en', slow=False)
           tts.save("output.mp3")
           playsound("output.mp3")   
           return True
    except sr.UnknownValueError:
        pass
    except sr.RequestError:
        pass
    return False

def process_command():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source, duration=2)
        print("Listening for command...")
        audio = recognizer.listen(source)
    try:
        text = recognizer.recognize_google(audio).lower()
        print(f"Recognized: {text}")
        if "reminder" in text.lower():
            tts = gTTS(text="What do you want to be reminded of?", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            with sr.Microphone() as source:
                recognizer.adjust_for_ambient_noise(source, duration=2)
                print("Listening for search query...")
                search_audio = recognizer.listen(source)
            try:
                reminder_text = recognizer.recognize_google(search_audio)
                print(f"Searching for: {reminder_text}")
            except sr.UnknownValueError:
                print("Sorry, I could not understand the search query.")
            except sr.RequestError:
                print("Sorry, there was an error with the Google Web Speech API.")
            tts = gTTS(text="when do you want me to remind you?", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            with sr.Microphone() as source:
                recognizer.adjust_for_ambient_noise(source, duration=2)
                print("Listening for search query...")
                search_audio = recognizer.listen(source)
            try:
                text = recognizer.recognize_google(search_audio)
                print(f"Searching for: {text}")
                #reminder_time=convert_to_time(text)
               
            except sr.UnknownValueError:
                print("Sorry, I could not understand the search query.")
            except sr.RequestError:
                print("Sorry, there was an error with the Google Web Speech API.")
            set_reminder(reminder_text, text)   
        elif "joke" in text:
            joke = fetch_joke()
            tts = gTTS(text=joke, lang='en', slow=False)
            tts.save("joke.mp3")
            playsound("joke.mp3")
        elif "youtube" in text:
            tts = gTTS(text="What do you want to search for?", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            with sr.Microphone() as source:
                recognizer.adjust_for_ambient_noise(source, duration=2)
                search_audio = recognizer.listen(source)
            search_text = recognizer.recognize_google(search_audio)
            webbrowser.get('firefox').open(f"https://www.youtube.com/results?search_query={search_text}")
        elif "weather" in text:
            tts = gTTS(text="Please specify the city name.", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            with sr.Microphone() as source:
                recognizer.adjust_for_ambient_noise(source, duration=2)
                city_audio = recognizer.listen(source)
            city_name = recognizer.recognize_google(city_audio)
            weather_report = get_weather(city_name)
            tts = gTTS(text=weather_report, lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
        elif "google" in text:
            tts = gTTS(text="What do you want to search for?", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            with sr.Microphone() as source:
                recognizer.adjust_for_ambient_noise(source, duration=2)
                search_audio = recognizer.listen(source)
            search_text = recognizer.recognize_google(search_audio)
            webbrowser.get('firefox').open(f"https://www.google.com/search?q={search_text}")
        elif "time" in text:
            current_time = datetime.now().strftime("%H:%M:%S")
            tts = gTTS(text=f"The current time is {current_time}", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
        elif "bye" in text:
            tts = gTTS(text="Bye, have a good day", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
            return True
        else:
            tts = gTTS(text="Sorry, I didn't recognize that command. Please try again.", lang='en', slow=False)
            tts.save("output.mp3")
            playsound("output.mp3")
    except sr.UnknownValueError:
        print("Sorry, I could not understand the audio.")
    except sr.RequestError:
        print("Sorry, there was an error with the Google Web Speech API.")
    return False

# Main loop
while True:
    if listen_for_command():
        if process_command():
            break

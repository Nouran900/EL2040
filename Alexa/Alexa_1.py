import speech_recognition as sr
from gtts import gTTS
from playsound import playsound

# Initialize recognizer class (for recognizing the speech)
recognizer = sr.Recognizer()

# Capture voice from the microphone
with sr.Microphone() as source:
    print("Adjusting for ambient noise... Please wait.")
    recognizer.adjust_for_ambient_noise(source, duration=1)
    print("Listening...")
    audio = recognizer.listen(source)

try:
    print("Recognizing...")
    # Using Google Web Speech API
    text = recognizer.recognize_google(audio)
    print(f"Recognized: {text}")
    
    # Convert recognized text to speech using gTTS
    tts = gTTS(text=text, lang='en', slow=False)
    tts.save("output.mp3")
    print("Playing the converted speech...")
    playsound("output.mp3")
except sr.UnknownValueError:
    print("Sorry, I could not understand the audio.")
except sr.RequestError:
    print("Sorry, there was an error with the Google Web Speech API.")

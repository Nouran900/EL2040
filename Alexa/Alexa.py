import speech_recognition as sr
from gtts import gTTS
from playsound import playsound
import webbrowser
from datetime import datetime
# Initialize recognizer class (for recognizing the speech)
recognizer = sr.Recognizer()
while True:
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
    if text=="open YouTube":
      # Convert recognized text to speech using gTTS
      tts = gTTS(text="opening youtube", lang='en', slow=False)
      tts.save("output.mp3")
      print("Playing the converted speech...")
      playsound("output.mp3")
      webbrowser.get('firefox').open("https://www.youtube.com/")
    if text=="open Google":
      # Convert recognized text to speech using gTTS
      tts = gTTS(text="opening google", lang='en', slow=False)
      tts.save("output.mp3")
      print("Playing the converted speech...")
      playsound("output.mp3")
      webbrowser.get('firefox').open("https://www.google.com/")
    if text=="what time is it":
      # Convert recognized text to speech using gTTS
      current_time = datetime.now().strftime("%H:%M:%S")
      tts = gTTS(text=current_time, lang='en', slow=False)
      tts.save("output.mp3")
      print("Playing the converted speech...")
      playsound("output.mp3") 
    if text=="hello":
      # Convert recognized text to speech using gTTS
      tts = gTTS(text="Hello Nouran how can i help you today?", lang='en', slow=False)
      tts.save("output.mp3")
      print("Playing the converted speech...")
      playsound("output.mp3") 
    if text=="close":
      # Convert recognized text to speech using gTTS
      tts = gTTS(text="Bye,have a good day", lang='en', slow=False)
      tts.save("output.mp3")
      print("Playing the converted speech...")
      playsound("output.mp3")
      break
       
 except sr.UnknownValueError:
    print("Sorry, I could not understand the audio.")
 except sr.RequestError:
    print("Sorry, there was an error with the Google Web Speech API.")

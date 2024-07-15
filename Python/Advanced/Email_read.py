import pyautogui as p
from time import sleep
import webbrowser as w

w.get('firefox').open("https://mail.google.com/mail/u/0/#inbox")
sleep(3)
p.click(441,202)
sleep(2)
p.click(520,237)
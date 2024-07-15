
import requests
import pyautogui as a
from time import sleep

def get_public_ip():
    response = requests.get('https://api.ipify.org/?format=json')
    data = response.json()
    return data['ip']

public_ip = get_public_ip()
print("Your public IP address is:", public_ip)

   
a.click(24,67)
sleep(4)
a.click(573,92)
a.write("https://whatismyipaddress.com/ip-lookup#google_vignette")
a.press("enter")
sleep(10)
a.click(469,636)
a.write(public_ip)
a.press("enter")

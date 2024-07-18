from tkinter import *

# Create the main window
window = Tk()
window.title("Canvas Arc Fill Example")
window.geometry("200x200")

def led_on():
   canvas.itemconfig(C1,fill="red")
def led_off():
   canvas.itemconfig(C1,fill="white")

# Create a canvas widget
canvas = Canvas(window, width=100, height=100, bg="white")
canvas.grid(row=0,column=0)

C1=canvas.create_oval(20,70,70,20)
Button(window,text="led on",command=led_on).grid(row=1,column=0)
Button(window,text="led off",command=led_off).grid(row=2,column=0)
window.mainloop()
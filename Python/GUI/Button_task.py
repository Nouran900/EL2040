from tkinter import *

window = Tk()
window.title("4_Buttons")
window.geometry("150x100")
window.configure(background="black")

# Place buttons with absolute positioning
Button(window, text="north", fg="red", bg="white",width=3).place(x=50, y=0)
Button(window, text="south", fg="green", bg="white",width=3).place(x=50, y=60)
Button(window, text="east", fg="grey", bg="white",width=3).place(x=100, y=30)
Button(window, text="west", fg="pink", bg="white",width=3).place(x=0, y=30)

window.mainloop()




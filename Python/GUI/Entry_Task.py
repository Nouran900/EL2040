from tkinter import *

tab=Tk()
tab.title("Reverse")
Label(tab,text="Enter the sentence :").grid(row=0)
E1=Entry(tab)
E1.grid(row=0,column=1)
def reverse():
    x=E1.get()
    E2.insert(0,x[::-1])

Button(tab,text="reverse",command=reverse).grid(row=2,column=2)
E2=Entry(tab)
E2.grid(row=1,column=1)
def delete():
    E1.delete(0,END)
    E2.delete(0,END)
Button(tab,text="try again",command=delete).grid(row=2,column=1)
tab.mainloop()
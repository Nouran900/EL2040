from tkinter import *
tab=Tk()
tab.title("Factorial")
tab.geometry("400x300")

def calc():
    x=int(E1.get())
    f=1
    for i in range(1,x+1) :
     f*=i
 
    E2.insert(0,f) 
    
Label(tab,text="enter the number :").grid(row=0,column=0)
E1=Entry(tab)
E1.grid(row=0,column=1)
E2=Entry(tab)
E2.grid(row=1,column=1)
Button(tab,text="Validate",command=calc).grid(row=1,column=3)
def delete():
    E1.delete(0,END)
    E2.delete(0,END)
Button(tab,text="try again",command=delete).grid(row=2,column=3)
tab.mainloop()
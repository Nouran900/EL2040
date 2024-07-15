from tkinter import *
tab=Tk()
tab.title("Sum&Sub")
tab.geometry("500x200")
Label(tab,text="Enter the value of the 1st Number:").grid(row=0)
Label(tab,text="Enter the value of the 2nd Number:").grid(row=1)
E1=Entry(tab)
E2=Entry(tab)
E3=Entry(tab)
E1.grid(row=0,column=1)
E2.grid(row=1,column=1)
E3.grid(row=2,column=1)
var=IntVar()
R1=Radiobutton(tab,text="Sum",variable=var,value=1)
R2=Radiobutton(tab,text="Sub",variable=var,value=2)
R1.grid(row=3)
R2.grid(row=4)
def print_1():
    x=int(E1.get())
    y=int(E2.get())
    if var.get()==1:
     s=x+y
     E3.insert(0,s)
    if var.get()==2:
      su=x-y
      E3.insert(0,su)      
Button(tab,text="Validate",command=print_1).grid(row=4,column=1)
tab.mainloop()
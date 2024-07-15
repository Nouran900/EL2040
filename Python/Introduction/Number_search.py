x=[4,4,6,44,4,8,4,54,4]
y=4  #the number we are searching for
i=0  #counter for loop
c=0  #counter for 4
t=len(x) #length of list
while i<= t-1:
    if y==x[i] :
        c+=1
    i+=1
print (c)    
#################
#w=list(input("enter the numbers you want :"))
w=x
p=int(input("enter the number you are searching for: "))
v=0
for j in range(len(w)):
   if p == x[j]:
       v+=1
print(f"the number {p} was found {v} times")       
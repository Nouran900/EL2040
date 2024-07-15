def init_portA():
   y=[]
   for i in range(8):
      x=input(f"please enter bit  {i} mode(in/out):")
      if x== "in" :
         y.append(0)
      else :
         y.append(1)
   return y             
         

g=init_portA()    

print ("".join(map(str,g[-1::-1])))
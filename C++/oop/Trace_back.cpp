#include<iostream>
class A
{
 
 public:
 
   static std::string arr[10];
   static int i;
   static void enterfn (const std::string& caller)
   {
     std::cout<<"Enter to "<<caller<<std::endl;
     print_BT(caller);
   }
   static void exitfn (const std::string& caller)
   {
      std::cout<<"Exit from "<<caller<<std::endl;
   }
   static void print_BT(const std::string& caller)
   {
     
     if(caller=="BT")
     {
        
       for(int j=0;j<i;j++)
       {
         std::cout<<j<<"-" <<arr[j]<<std::endl;
       }
     }
     else
     {
        arr[i]=caller;
        i++;
       
     }
   }
};
std::string A::arr[10];  
int A::i=0;
void fun3(int x)
{
    A::enterfn("fun3");
    A::print_BT("BT");
    A::exitfn("fun3");
}
void fun2(int x)
{
    A::enterfn("fun2");
    fun3(2);
    A::exitfn("fun2");
}
void fun1(int x)
{
    A::enterfn("fun1");
    fun2(2);
    A::exitfn("fun1");
}
int main()
{
    A::enterfn("main");
    fun1(2);
    A::exitfn("main");
    return 0;
}
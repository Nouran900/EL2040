#include<iostream>

int main(){
   char arr[94];
   std::cout<<" ----"<<" * *"<<"----"<<std::endl;
   std::cout<<"|CHAR"<<" | "<<"ASCII|"<<std::endl;
   std::cout<<" ----"<<" * *"<<"----"<<std::endl;
   for (int i =0;i<=32;i++)
   {
    std::cout<<"|"<<"    |   "<<i<<" |"<<std::endl;
   }
   for(int i=33;i<=127;i++)
   {
       std::cout<<"|"<<char(i)<<"   |   "<<i<<" |"<<std::endl;
   }
}
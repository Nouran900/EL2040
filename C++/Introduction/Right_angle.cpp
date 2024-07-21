#include<iostream>
void Right_angle_or_not(int a,int b,int c);
int main(){
    int x;
    int y;
    int z;

    std::cout <<"enter the first angle :";
    std::cin >>x;
    std::cout<<std::endl;
    std::cout <<"enter the 2nd angle :";
    std::cin >>y;
    std::cout<<std::endl;
    std::cout <<"enter the 3rd angle :";
    std::cin >>z;
    std::cout<<std::endl;
    Right_angle_or_not(x,y,z);

 
}
void Right_angle_or_not(int a,int b,int c)
{
    int sum=a+b+c;
   if(sum==180) 
   {
    if(a==90&& b!=90&& c!=90)
     std::cout<<"this is a right angle triangle "<<std::endl;
    else if(a!=90&& b==90&& c!=90)
     std::cout<<"this is a right angle triangle "<<std::endl;
    else if(a==90&& b==90&& c==90)
     std::cout<<"this is a right angle triangle "<<std::endl;
    else
     std::cout<<"this isn't a right angle triangle "<<std::endl; 
   }
   else
   {
     std::cout<<"this isn't a  triangle "<<std::endl; 
   }
      
}
#include<iostream>
int max(int a,int b,int c);
int main(){
    int x;
    int y;
    int z;

    std::cout <<"enter the first number :";
    std::cin >>x;
    std::cout<<std::endl;
    std::cout <<"enter the 2nd number :";
    std::cin >>y;
    std::cout<<std::endl;
    std::cout <<"enter the 3rd number :";
    std::cin >>z;
    std::cout<<std::endl;
    int maximum =max(x,y,z);
    std::cout<<"The max of these three numbers is "<< maximum<<std::endl;
 
}
int max(int a,int b,int c)
{
    int m=a;
    if(m<b)
      m=b;
    if (m<c)
      m=c;
    return m;
}
#include<iostream>
void MULTI_table(int a);
int main()
{
    int numb;
    std::cout<<"enter the number :";
    std::cin>>numb;
    MULTI_table(numb);
}
void MULTI_table(int a)
{
    std::cout<<"the multiplication table of "<<a<<std::endl;   
    for(int i=0;i<=10;i++)
    {
       
        std::cout<<a*i<<std::endl;
        
    }
   

}
#include<iostream>

int main()
{
    int value;
    auto square_root=[](int number)
    {
         return number*number;
    };
    std::cout<<"Enter the number: ";
    std::cin>>value;
    std::cout<<square_root(value)<<std::endl;


}
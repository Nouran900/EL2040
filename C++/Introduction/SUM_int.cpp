#include<iostream>

int main ()
{
    int numb;
    int sum=0;
    int count;
    std::cout<<"Enter the number:";
    std::cin>>numb;
    //now we want to separate the number and convert it to a unit digit
    while(numb != 0)
    {
        count=numb%10;

        sum+=(count);
        numb/=10;

    }
    std::cout<< "the summation is " << sum <<std::endl;
}    
#include<iostream>
void get_even_odd(int arr[],int size)
{
    int i;
    int arr_even[size];
    int even=0;
    int arr_odd[size];
    int odd=0;
    for(i=0;i<size;i++)
    {
        if (arr[i]%2==0)
        {
            arr_even[even]=arr[i];
            even++;
        }
        else
        {
           arr_odd[odd]=arr[i];
            odd++;
        }

    }
    if(even!=0)
    {
      std::cout<<"The even numbers in this array are :"<<std::endl;
      for(i=0;i<even;i++)
      std::cout<<arr_even[i]<<" ";
    }
     if(odd!=0)
    {
      std::cout<<std::endl;
      std::cout<<"The odd numbers in this array are :"<<std::endl;
      for(i=0;i<odd;i++)
      std::cout<<arr_odd[i]<<" ";
    }
     std::cout<<std::endl;
}
int main()
{
  
    int number_of_elements;
    int *arr=new int[ number_of_elements];
     std::cout<<"enter the number of elements in the list:";
     std::cin>>number_of_elements;
      std::cout<<std::endl;
    std::cout<<"enter the list of numbers you want:";
    for(int i=0;i !=  number_of_elements;i++)
    {
       std::cin>> arr[i];
    }
    get_even_odd(arr,number_of_elements);
   

}
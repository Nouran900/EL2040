#include<iostream>
int find_max (int arr[],int size)
{
    int max=arr[0];
    for (int i=0;i<size;i++)
    {
        if(max<arr[i+1])
        {
            max=arr[i+1];
        }
    }
    return max;
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
    int is_max=find_max(arr,number_of_elements);
    std::cout<<"the max number is this array is :" << is_max<<std::endl;
}
#include<iostream>
int search (int arr[],int size,int number_to_find)
{
    
    int y=false;
    for (int i=0;i<size;i++)
    {
        if(arr[i]==number_to_find)
        {
            y=i;
        }
    }
    return y;
}
int main()
{   
    int number;
    int arr[10]={1,5,7,9,6,4,44,66,88,90};
     std::cout<<"enter the number you want to search for inside the list:";
     std::cin>>number;
      std::cout<<std::endl;
    int found=search(arr, sizeof(arr)/sizeof(arr[0]),number);
    if (found==false)
    std::cout<<"the  number isn't in the array " <<std::endl;
    else
    std::cout<<"the  number is in the array at index " << found<<std::endl;
}

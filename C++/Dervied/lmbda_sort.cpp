#include<iostream>

int main()
{

    int number_of_elements;
    int *ptr=new int[ number_of_elements];
     std::cout<<"enter the number of elements in the list:";
     std::cin>>number_of_elements;
      std::cout<<std::endl;
    std::cout<<"enter the list of numbers you want:";
    for(int i=0;i !=  number_of_elements;i++)
    {
       std::cin>> ptr[i];
    }
    auto sort=[](int arr[],int size)
    {
        int i=0;
        int x=1;
        for(i=0;i<size;i++)
        {
           for(int j=i;j<size;j++)
            {if(arr[i]>arr[j])
            {
               int r=arr[j];
               arr[j]=arr[i];
               arr[i]=r;
            }
            
            }
        }
        std::cout<<"Ascending order :"<<std::endl;
        for(int j=0;j<size;j++)
        {
            std::cout<<arr[j]<<" ";
        }
        std::cout<<std::endl;
        std::cout<<"Desending order :"<<std::endl;
        for(int j=size-1;j>=0;j--)
        {
            std::cout<<arr[j]<<" ";
        }
        std::cout<<std::endl;
    };
    sort(ptr,number_of_elements);
   return 0;
}

#include<iostream>
int search (int arr[],int size,int number_to_find)
{
    
    int y=-1;
    for (int i=0;i<size;i++)
    {
        if(arr[i]==number_to_find)
        {
            y=i;
        }
    }
    return y;
}
void remove(int arr[],int& size,int index)
{
    int x;
    for(x=index;x<size-1;x++)
    {
        arr[x]=arr[x+1];
    }
    size--;
}
int main()
{   
    int number;
    int  size_1=10;
    int* arr=new int[size_1];
    for(int i=0;i<size_1;i++)
    {
        arr[i]=2*i;
    }
    std::cout<<"enter the number you want to delete from the list:";
    std::cin>>number;
    std::cout<<std::endl;
    int found=search(arr, size_1,number);
    if (found==-1)
    std::cout<<"the  number isn't in the array " <<std::endl;
    else
    {
        remove(arr, size_1,found);
        std::cout<<"the  number is deleted" <<std::endl;
        std::cout << "Updated array: ";
        for (int i = 0; i < size_1; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "New size of the array: " << size_1 << std::endl;
    }
    return 0;
}
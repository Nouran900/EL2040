#include<iostream>
int* merge(int first_arr[],int first_size,int sec_arr[],int sec_size)
{
   int i;
   int *ptr=first_arr;
   for (i=first_size;i<sec_size;i++)
   {
    int x=0;
    ptr[i]=sec_arr[x];
    x++;
   }
   return ptr;
}
int main()
{
    int arr_1[4]={1,2,3,4};
    int arr_2[4]={5,6,7,8};
    int size_1=sizeof(arr_1)/sizeof(arr_1[0]);
    int size_2=sizeof(arr_2)/sizeof(arr_2[0]);
    int* arr_3=merge(arr_1,size_1,arr_2,size_2);
    for(int i=0;i!=size_1+size_2-1;i++)
    {
      std::cout<<arr_3[i]<<"";
    }
    std::cout<<std::endl;
    return 0;
}
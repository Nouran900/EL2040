
#include<iostream>

class function{
  public:
    static void Isdigit(char letter)
    {
      if(((int )(letter)>64&&(int )(letter)<91)|| ((int )(letter)>96&& (int )(letter)<123))
      {
        std::cout<<"the character isnt a digit"<<std::endl;
      }
      else
      {
        std::cout<<"the character is a digit"<<std::endl;
      }
    } 
    static void IsEven(int array[], int size)
    {
      int count=0;
      for (int i =0;i<size;i++)
      {
        if (array[i]%2==0)
        {
          count++;
        }
      }
      
      if(count==size)
      {
        std::cout<<"the array is all even numbers"<<std::endl;
      }
      else
      {
        std::cout<<"the array isnt all even numbers"<<std::endl;
      }
    } 
    static void IsEvenFound (int array[], int size)
    {
        int count=0;
      for (int i =0;i<size;i++)
      {
        if (array[i]%2==0)
        {
          count++;
        }
      }
      
      if(count !=0)
      {
        std::cout<<"the array contains "<< count <<" even numbers"<<std::endl;
      }
      else
      {
        std::cout<<"the array is all odd numbers"<<std::endl;
      }
    }
};
int main()
{
    char character;
    int arr[]={3,55,5,7};
    int size =sizeof(arr)/sizeof(arr[0]);
    function::IsEven(arr,size);
    function::IsEvenFound(arr,size);
    std::cout<<"please enter a charater:"<<std::endl;
    std::cin>>character;
    function::Isdigit(character);
    return 0;
}
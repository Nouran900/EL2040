#include<iostream>
#include<cmath>

int main(){
    //before using bit set 
    
    int choice ;
    int numb;
    int x=0;
    int i=0;
    int last=0;
    int sum=0;
    int arr[20]={};
    std::cout<<"Type 1 or 2 based on your choice:"<<std::endl<<"1)convert dec to bin"<<std::endl<<"2)convert bin to dec"<<std::endl;
    std::cin>>choice;
    switch(choice)
    {
    case 1:
    //converting from dec to binary
       {std::cout<<"Enter the number you want to convert to binary:";
        std::cin>>numb;
       for( i=0;numb !=0;i++)
        {
           x=numb%2;
           arr[i]=x;
           numb/=2;
        }
      for(last=i;last!=-1;last--)
        {
          std::cout<<arr[last];
        }
        std::cout<<std::endl;
        break;}
    case 2:

       {//converting from binary to dec
       std::cout<<"Enter the number you want to convert to decimal:";
        std::cin>>numb;
        
        while(numb != 0)
          {   
           i=numb%10;
            
             arr[x]=i;
            x++;
            numb/=10;
          } 
        for( last=x-1;last >=0;last--)  
          {
            
            if(arr[last]==1)
              {sum+=pow(2,last);
              } 
        }
         std::cout<<sum<<std::endl;
    
       }
    }

}
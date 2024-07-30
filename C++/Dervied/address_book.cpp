
#include<iostream>
#include<limits>
int main()
{

  int choice;
  int number_of_elements;
  int size=30;
  int space=0;
  int last=0;
  std::string arr[size];
 
  bool enter=true;
  while(enter)
  {
    
   std::cout<<"----------------------------"<<std::endl<<"welcome to your favourite address book"<<std::endl<<"what do you want to do?"
   <<std::endl<<"1-list" <<std::endl<<"2-Add" <<std::endl<<"3-Delete" <<std::endl<<"4-Delete all"
   <<std::endl<<"5-Search" <<std::endl<<"6-Close"<<std::endl<<"Type the number of your choice: ";
   std::cin>>choice;
   switch(choice)
   {
    
     case 1:
      {
       if(space==0)
       {
        std::cout<<"No contact found"<<std::endl;
       }
       else
       {
        for(int i=0;i<space;i++)
        {
         std::cout<<arr[i]<<std::endl;
        } 
       }
    
     break;
      }
    case 2:
     {
       std::cout<<"enter the number of contacts you want to add :";
       std::cin>>number_of_elements;
       space+=number_of_elements;
       std::cout<<space<<std::endl;
       if (space>size)
        {
         std::cout<<"sorry no more space"<<std::endl;
        }
       else
        {
        
         std::cout<<"enter the name of contact you want to add:";
         int i;
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
         for(i=last;i < last+number_of_elements;i++)
          {
           std::getline(std::cin, arr[i]);
          }
     
         last=i;
        }
     
    break;
     }
    case 3:
    {
        int i;
        std::string name;
        std::cout<<"enter the name of contact you want to delete: "<<std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::getline(std::cin, name);
        for( i=0;i<space;i++)
         {
          if(name==arr[i])
            {
              for(int x=i;x<space-1;x++)
               {
                 arr[x]=arr[x+1];
               }
             std::cout<<"contact is deleted "<<std::endl;
             space--;
             last--;
             break;
            }
          if(i==space-1)
           {
            std::cout<<"contact not found "<<std::endl;
           }
         }
      
    
    break;
    }
    case 4:
    {
       space=0;
       last=0;
       std::cout<<"All contacts are deleted "<<std::endl;
       
    }
    break;
    case 5:
    {
       int i;
       std::string name;
       std::cout<<"enter the name of contact you want to search for: "<<std::endl;
       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
       std::getline(std::cin, name);
       for( i=0;i<space;i++)
        {
          if(name==arr[i])
           {
            std::cout<<"contact found"<<std::endl;
            break;
           }
        
        }
      if(i==space)
        {
         std::cout<<"contact not found"<<std::endl;
        }

    
    break;
    }
    case 6:
    {
        enter =false;
    break;
    }
    default:
    {
        std::cout<<"invalid choice"<<std::endl;
    break;
    }
   }
  
  }
   return 0;
}
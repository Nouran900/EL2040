#include <iostream>
#include<cstring>
class string_NEW
{
   private:
   int length;
   char* str;
   public:
   string_NEW(const char* msg)
   {
    
    length=strlen(msg);
     str = new char[length + 1];
     strcpy(str,msg);

   }
   void display()
   {
    std::cout<<str<<std::endl;
   }
   void get_length()
   {
    std::cout<<length<<std::endl;
   }
     
};

int main()
{
    string_NEW A("hello");
    A.display();
    A.get_length();

    return 0;
}
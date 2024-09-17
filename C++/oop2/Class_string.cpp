#include<iostream>
#include<cstring>
class string
{
  private:
   int size;
   char* str;
  public:
  string (const char*msg)//constructor
  {
    std::cout<<"constructor"<<std::endl;
    this->size=strlen(msg);
    this->str=new char[size+1];
    strcpy(this->str,msg);
  }
  string (const string &obj)//copy constructor
  {
    std::cout<<"Copy constructor"<<std::endl;
    this->size=obj.size;
    this->str=new char[size+1];
    strcpy(this->str,obj.str);
  }
  string ( string &&obj)//move constructor
  {
    std::cout<<"Move constructor"<<std::endl;
     
    
      
      this->size=obj.size;
      this->str=obj.str;
      obj.str=nullptr;
      obj.size=0;
    
  }
  string &operator = (const string &obj)//copy assignment
  {
    std::cout<<"copy assignment"<<std::endl;
     if(this!=&obj)
     {
     this->size=obj.size;
     this->str=new char[size+1];
     strcpy(this->str,obj.str);
     }
     return *this;
     
  }
  string &operator = ( string &&obj)//move assignment
  {
     std::cout<<"Move assignment"<<std::endl;
     if(this!=&obj)
    {
      delete[] str;
      this->size=obj.size;
      this->str=obj.str;
      obj.str=nullptr;
      obj.size=0;
    }
    return *this;
  }
  ~string ()//destructor
  {
     std::cout<<"destructor"<<std::endl;
     delete [] str;
  }
  void print()
  {
       if (str) {
        std::cout << str << std::endl;
        }
       else {
        std::cout << "Empty or moved string" << std::endl;
    }
  }

};

int main()
{
    string N1 = "Nouran";
    string N2(N1);           // Copy constructor
    string N3(std::move(N1)); // Move constructor
    string N4 = N2;           // Copy constructor
    string N5 = std::move(N2); // Move constructor
    
    // Now trigger the assignment operators
    N5 = N4;  // This will call the copy assignment operator
    N3 = std::move(N5); // This will call the move assignment operator

    N1.print();
    N2.print();
    N3.print();
    N4.print();
    N5.print();

    return 0;
}

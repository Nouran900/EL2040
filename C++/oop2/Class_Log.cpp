#include<iostream>
#include <vector>
enum level
{
    info,
    warn,
    error
};

struct logentry
{
  std::string msg;
  level numb;
};
class LOG
{
    private:
     static std::vector<logentry> mymsg;
    public:
     static void level(const std::string & msg,level numb)
     {
       //creat struct
       logentry n ={msg,numb};
       //add it ti my vector
       mymsg.push_back(n);
     }

     static void dump()
     {
         for(auto &i:mymsg)
         {
           std::string level_str;
            switch (i.numb)
            {
                case info: level_str = "INFO"; break;
                case warn: level_str = "WARNING"; break;
                case error: level_str = "ERROR"; break;
            }
            std::cout << "[" << level_str << "] " << i.msg << std::endl;
         }
     }

     static void clear ()
     {
       mymsg.clear();
     }
     


};
std::vector<logentry> LOG::mymsg;
int main()
{
    LOG::level("failed to open", error);
    LOG::level("file opened sucessfully", info);
    LOG::level("forgot to close the file", warn);
    LOG::dump();
    LOG::clear();
    LOG::dump();

    return 0;
}
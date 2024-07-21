#include<iostream>
void vowel(char a);
int main()
{
    char letter;
    std::cout<<"enter the letter :";
    std::cin>>letter;
    vowel(letter);
}
void vowel(char a)
{
    char arr[6]="aeiou";
    for(int i=0;i<=6;i++)
    {
        if (a==arr[i])
        { std::cout<<"the letter is a vowel letter"<<std::endl;
        break;}
         if(i==5)
         std::cout<<"the letter isn't a vowel letter"<<std::endl;
    }
   

}
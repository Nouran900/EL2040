#include <iostream>
#include <bitset>
#include <string>

int main() {
    int choice ;
    std::cout<<"Type 1 or 2 based on your choice:"<<std::endl<<"1)convert dec to bin"<<std::endl<<"2)convert bin to dec"<<std::endl;
    std::cin>>choice;
    switch(choice)
    {
    case 1:
     {//converting from dec to binary
     // Declare the decimal number
    unsigned int decimal;

    // Input the decimal number
    std::cout << "Enter a decimal number: ";
    std::cin >> decimal;

    // Define a bitset with enough bits to represent the number
    // For example, using 16 bits (adjust the size as needed)
    std::bitset<16> binary(decimal);

    // Output the binary representation
    std::cout << "Binary representation: " << binary << std::endl;
    break;}
    case 2:
     { //converting from binary to dec 
    // Define the binary string
    std::string binaryStr;

    // Input the binary string
    std::cout << "Enter a binary number: ";
    std::cin >> binaryStr;

    // Define a bitset with the size equal to the length of the binary string
    std::bitset<32> binary(binaryStr);  // Adjust the size as needed

    // Convert the bitset to a decimal number
    unsigned long decimal = binary.to_ulong();

    // Output the decimal representation
    std::cout << "Decimal representation: " << decimal << std::endl;
    break;}
    }
    return 0;
}

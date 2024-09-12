#include <iostream>
#include <numeric> // For std::iota
#include <array>   // For std::array or you can use std::vector

int main() {
    const int size = 9991; // 10000 - 10 + 1
    std::array<int, size> arr; // Declare an array of the required size

    // Use std::iota to fill the array
    std::iota(arr.begin(), arr.end(), 10);

    // Printing the first and last elements to verify
    std::cout << "First element: " << arr[0] << std::endl;
    std::cout << "Last element: " << arr[size - 1] << std::endl;

    return 0;
}

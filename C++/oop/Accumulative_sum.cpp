#include <iostream>
#include <numeric>  // For std::accumulate
#include <array>    // For std::array

int main() {
    std::array<int, 5> arr = {1, 2, 3, 4, 5}; // Example array

    // Calculate the sum of the array elements
    int sum = std::accumulate(arr.begin(), arr.end(), 0);

    std::cout << "The sum of the array elements is: " << sum << std::endl;

    return 0;
}

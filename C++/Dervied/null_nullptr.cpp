#include <iostream>

// Function overloads
void processPointer(int* ptr) {
    std::cout << "Called processPointer(int* ptr)\n";
}

void processPointer(std::nullptr_t ptr) {
    std::cout << "Called processPointer(std::nullptr_t ptr)\n";
}

int main() {
    // Using NULL
    // Uncomment the line below to see the compilation error
    // processPointer(NULL);

    // Using nullptr
    processPointer(nullptr);

    return 0;
}

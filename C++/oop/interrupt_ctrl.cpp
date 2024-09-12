#include <iostream>
#include <csignal>

// Signal handler function
void signalHandler(int signum) {
    std::cout << "\nInterrupt signal (" << signum << ") received.\n"<<std::endl<<"goodbye"<<std::endl;
    // Cleanup and close program here
    exit(signum); // Exit the program
}

int main() {
    // Register signal handler for SIGINT (Ctrl + C)
    signal(SIGINT, signalHandler);

    // Infinite loop to keep the program running
    while(true) {
        std::cout << "Program running... Press Ctrl + C to stop.\n";
       // std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep for 1 second
    }

    return 0;
}

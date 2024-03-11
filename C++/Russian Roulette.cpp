#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    std::srand(std::time(nullptr)); 
    const int chambers = 6; 
    int bulletPosition = std::rand() % chambers + 1; 

    std::cout << "Welcome to Russian Roulette!" << std::endl;
    for (int i = 1; i <= chambers; ++i) {
        std::cout << "Press enter to pull the trigger..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        if (i == bulletPosition) {
            std::cout << "Bang! You're dead." << std::endl;
            break;
        } else {
            std::cout << "Click! You're safe... for now." << std::endl;
        }
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main() {
    std::srand(std::time(nullptr)); // Seed random number generator
    const int chambers = 6; // Number of chambers in the revolver
    int bulletPosition = std::rand() % chambers + 1; // Randomly place the bullet in a chamber

    std::cout << "Welcome to Russian Roulette!" << std::endl;
    for (int i = 1; i <= chambers; ++i) {
        std::cout << "Press enter to pull the trigger..." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer and wait for Enter

        if (i == bulletPosition) {
            std::cout << "Bang! You're dead." << std::endl;
            break;
        } else {
            std::cout << "Click! You're safe... for now." << std::endl;
        }
    }

    return 0;
}

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    int arr[8][8];


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            arr[i][j] = 1;
        }
    }


    std::srand(std::time(nullptr));

    int sum = 64; 

    while (sum < 128) {

        int i = std::rand() % 8;
        int j = std::rand() % 8;

      
        int small_number = std::rand() % (128 - sum) + 1; // random number between 1 and (128 - sum)
        arr[i][j] += small_number;

        sum += small_number;
    }

    std::cout << "Array: " << std::endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Sum of all values in the array: " << sum << std::endl;

    return 0;
}

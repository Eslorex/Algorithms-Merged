#include <stdio.h>

int main() {
    int array1[] = {1, 5, 3, 4, 5};
    int array2[] = {5, 5, 5, 6, 7};
    int array1Size = sizeof(array1) / sizeof(array1[0]);
    int array2Size = sizeof(array2) / sizeof(array2[0]);
    int counts[1000] = {0}; 
    int maxCount = 0;
    int mostCommon;

    for (int i = 0; i < array1Size; i++) {
        counts[array1[i]]++;
    }
    for (int i = 0; i < array2Size; i++) {
        counts[array2[i]]++;
    }

    for (int i = 0; i < 1000; i++) {
        if (counts[i] > maxCount) {
            maxCount = counts[i];
            mostCommon = i;
        }
    }

    printf("The most common member is %d with a count of %d\n", mostCommon, maxCount);

    return 0;
}

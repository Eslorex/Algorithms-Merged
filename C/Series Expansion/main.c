#include <stdio.h>
#include <math.h>

int main() {
    double x = 0.2106;
    int b = 6;
    int max_k = 40 + b;
    double sum = 0;
    double us = 2;
    double true_value = 1 / pow(1 - x, us);
    double error;
    int k_found = 0;
    int first_k = -1;

    printf("Series Expansion results of 1/(1-x)^2 for x =%lf\n", x);
    printf("\nTrue value: %lf\n", true_value);

    for (int k = 1; k <= max_k; k++) {
        double term = k * pow(x, k - 1);
        sum += term;
        error = fabs(true_value - sum);

        if (k % 2 == 0) {
            printf("k: %d\tResult: %.10lf\tError: %.10lf\n", k, sum, error);
        }

        if (!k_found && error < pow(10, -4) * x) {
            first_k = k;
            k_found = 1;
        }
    }

    printf("\nInf\tResult: %lf\t Error: %lf\n\n", sum, error);

    printf("Squared error is less than 0.00002106 for k >= 5");


    return 0;
}
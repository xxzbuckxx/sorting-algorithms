#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

static double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; fabs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

double Log(double x, uint64_t terms) {
    // Calculate arccos taylor series at sqrt(1 - x^2)

    double guess = x, previous;
    double n = x;
    double d_factorial = 1;

    // keep going till k term is less than epsilon
    for (uint64_t k = 0; fabs(guess - previous) > terms; k += 2) {
        previous = guess;
        guess = previous - 1.0 + x / Exp(x);
        printf("k is %lu, output is %3.5f\n", k, guess);
    }

    printf("%12.15f is the last term out of %lu\n", guess, terms);

    return guess;
}

int main() {
    printf("%4.12f\n", Log(1, 5));
    return 0;
}

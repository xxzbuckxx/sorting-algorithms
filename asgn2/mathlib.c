#include "mathlib.h"
#include <stdio.h>
#include <stdint.h> // extended integer library
#include <math.h> // Pi

#define EPSILON 1e-10

double arcSin(double x) {
    // Implement
    // Factorial
    double output = x, term = x;
    uint32_t k = 0;
    const double sqr = x * x;

    double n = x;
    double d_factorial = 1;


    // keep going till k term is less than epsilon
    while (term > EPSILON) {
        k++;
        n *= k*sqr;
        d_factorial *= k + 1;

        term = n / (d_factorial * (k + 2));
        output += term;
    }

    return output;
}

double arcCos(double x) {
    // Implement
    return x;
}

double arcTan(double x) {
    // Implement
    return x;
}

double Log(double x) {
    // Implement
    return x;
}

int main(){
    printf(" calculated %16.12f should be %16.12f\n", arcSin(0.5), M_PI / 6.0);
    return 0;
}

#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

double arcSin(double x, uint64_t terms) {
    double output = x, term = x;
    uint64_t k = 0;
    const double sqr = x * x;

    double n = x;
    double d_factorial = 1;

    // keep going till k term is less than epsilon
    // while (((k + 2) / 2)  <= terms) {
    while (term > EPSILON) {

        k += 2;

        n *= (k - 1) * sqr;
        d_factorial *= k;

        /* printf("%3.5f\n", d_factorial); */
        term = n / (d_factorial * (k + 1));
        printf("%lu\n", k + 1);
        output += term;

        printf("k is %lu, output is %3.5f\n", k, output);
    }

    printf("%12.15f is the last term out of %lu\n", term, terms);
    return output;
}

int main() {
    printf("%4.12f\n",  arcSin(1, 80));
    return 0;
}

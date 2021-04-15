#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

double Sqrt(double x) {
    double y = 1.0;
    for (double guess = 0.0; fabs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

double arcSin(double x, uint64_t terms) {
    // Calculate arccos taylor series at sqrt(1 - x^2)

    double output, term;

    int use_arcos = fabs(x) > 0.7;

    if (use_arcos) {
        printf("using cos bull\n");
        x = Sqrt(1 - x * x);
        output -= M_PI_2;
    }

    output += x;
    term = x;

    printf("x is %2.15f and output is %f", x, output);

    uint64_t k = 0;
    const double sqr = x * x;

    double n = x;
    double d_factorial = 1;

    // keep going till k term is less than epsilon
    while (((k + 2) / 2) <= terms) {

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

    return (use_arcos) ? -output : output;
}

int main() {
    printf("%4.12f\n", arcSin(1, 1));
    return 0;
}

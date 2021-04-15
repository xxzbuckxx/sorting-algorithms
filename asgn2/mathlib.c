#include "mathlib.h"

#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

// fabs and Exp taken from proff long

inline double fabs(double x) {
    return x > 0 ? x : -x;
}

double Sqrt(double x) {
    double y = 1.0;
    for (double guess = 0.0; fabs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; fabs(term) > EPSILON; k += 1) {
        term *= x / k;
        sum += term;
    }
    return sum;
}

double arcSin(double x) {
    double output = 0;
    int use_arcos = fabs(x) > 0.7;
    int correct = x > 0;

    // Calculate arccos taylor series at sqrt(1 - x^2)
    if (use_arcos) {
        x = Sqrt(1 - x * x);
        output -= M_PI_2;
    }

    output += x;
    double term = x;

    uint64_t k = 0;
    const double sqr = x * x;

    double n = x;
    double d_factorial = 1;

    while (fabs(term) > EPSILON) {
        k += 2;

        n *= (k - 1.0) * sqr;
        d_factorial *= k;

        term = n / (d_factorial * (k + 1.0));
        output += term;
    }
    return (correct & use_arcos) ? -output : output;
}

double arcCos(double x) {
    return M_PI_2 - arcSin(x); // M_PI_2 = pi / 2
}

double arcTan(double x) {
    return arcSin(x / sqrt(x * x + 1));
}

double Log(double x) {
    // Implement
    return x;
}

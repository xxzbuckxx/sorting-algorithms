#include "mathlib.h"

#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

// fabs, Sqrt, and Exp taken from proff long

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

//
// Returns the value of arcSin(x) using a Taylor series approximation
//
// x: value that is being evaluated
//
double arcSin(double x) {
    double output = 0;
    int use_arccos = fabs(x) > 0.7;
    int correct = x > 0;

    // Calculate arccos taylor series at sqrt(1 - x^2)
    if (use_arccos) {
        x = Sqrt(1 - x * x);
        output -= M_PI_2;
    }

    double n = x;
    const double sqr = x * x;
    double d_factorial = 1;
    double term = x;
    output += x;

    for (uint64_t k = 2; fabs(term) > EPSILON; k += 2) {
        n *= (k - 1.0) * sqr;
        d_factorial *= k;
        term = n / (d_factorial * (k + 1.0));
        output += term;
    }
    return (correct & use_arccos) ? -output : output;
}

//
// Returns the value of arccos(x) using arcSin function Taylor series
//
// x: value that is being evaluated
//
double arcCos(double x) {
    return M_PI_2 - arcSin(x); // M_PI_2 = pi / 2
}

//
// Returns the value of arctan(x) using arcSin function Taylor series
//
// x: value that is being evaluated
//
double arcTan(double x) {
    return arcSin(x / Sqrt(x * x + 1));
}

//
// Returns the value of Log(x) using newton's method of natural log
//
// x: value that is being evaluated
//
double Log(double x) {
    // !!! Fix - for 1
    double guess = x, previous;

    // keep going till newest term is less than epsilon
    do {
        previous = guess;
        guess = previous - 1 + (x / Exp(previous));
    } while (fabs(guess - previous) > EPSILON);

    return guess;
}

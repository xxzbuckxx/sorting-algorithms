#include "mathlib.h"

#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

// fabs, Sqrt, and Exp taken from proff long

static inline double fabs(double x) {
    return x > 0 ? x : -x;
}

static double Sqrt(double x) {
    double y = 1.0;
    for (double guess = 0.0; fabs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

static double Exp(double x) {
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
    // Boolean checks
    int use_arcos = fabs(x) > 0.7;
    int correct = use_arcos && x > 0; // Correct for wrong sign when using arccos series

    // Use arccos taylor series at sqrt(1 - x^2)
    if (use_arcos) {
        x = Sqrt(1 - x * x);     // arcsin(x) = arccos(sqrt(1 - x^2))
        output -= M_PI_2;        // arcos = pi/2 - arcsin
    }

    // Initialize
    double n = x;                // numerator
    const double xsqr = x * x;
    double d_factorial = 1;      // factorial in denominator
    double term = x;
    output += x;

    // Compute series until |term| <= 1e-10
    for (uint64_t k = 0; fabs(term) > EPSILON; k += 2) {
        n *= (k - 1.0) * xsqr;   // Compute numerator
        d_factorial *= k;        // Compute factorial
        term = n / (d_factorial * (k + 1.0)); // Compute term
        output += term;
    }
    return (correct) ? -output : output; // Correct using arccos series and x > 0
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
    return arcSin(x / sqrt(x * x + 1));
}

//
// Returns the value of Log(x) using newton's method of natural log
//
// x: value that is being evaluated
//
double Log(double x) {
    // Implement
    return x;
}

#include "mathlib.h"

#include <math.h> // Pi
#include <stdint.h> // extended integer library
#include <stdio.h>

#define EPSILON 1e-10

// fabs, Sqrt, and Exp taken from proff long from piazza

//
// Takes the absolute value of a double
//
// x: a double
//
inline double fabs(double x) {
    return x > 0 ? x : -x;
}

//
// Square root using Bisection
//
// x: a double
//
double Sqrt(double x) {
    double y = 1.0;
    // Bisects until difference between guess and bisection is less than epsilon
    for (double guess = 0.0; fabs(y - guess) > EPSILON; y = (y + x / y) / 2.0) {
        guess = y;
    }
    return y;
}

//
// E to the x using Newton's Method
//
// x: a double
//
double Exp(double x) {
    double term = 1, sum = 1;
    // Finds new terms until latest ter is less than epsilon
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
    int correct = use_arccos && x > 0;

    // Calculate arccos taylor series at sqrt(1 - x^2)
    if (use_arccos) {
        x = Sqrt(1 - x * x);
        output -= M_PI_2;
    }

    double n = x; // Numerator
    const double sqr = x * x; // x squared
    double d_factorial = 1; // Denomenator Factorial
    double term = x; // Term
    output += x; // Sum terms

    // Find terms until latest term is less than Epsilon
    for (uint64_t k = 2; fabs(term) > EPSILON; k += 2) {
        n *= (k - 1.0) * sqr; // Numerator
        d_factorial *= k; // Denomenator Factorial
        term = n / (d_factorial * (k + 1.0)); // Term
        output += term; // Sum terms
    }
    return (correct) ? -output : output; // corect for sign when arcos and positive
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
    double guess = x, previous;

    // keep going till newest term is less than epsilon
    // Using do because previous not defined
    do {
        previous = guess;
        guess = previous - 1 + (x / Exp(previous));
    } while (fabs(guess - previous) > EPSILON);

    return guess;
}

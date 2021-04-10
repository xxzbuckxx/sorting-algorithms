# Basic Arithmetic Operations

* computers only do basic arithmetic operations
* u can call a sin or cos but you should know what is happening underneath
* abs value the math library can probably do faster

**Check the man page for things**

# computing sin(x)

* Periodic on [-2pi, 2pi] meaning that sin(9pi) = sin(pi)
	* use modulus on floating point

# computing log(x)

* new = 1/2 * (old + n/old)

```C

double Log(double x) {
	doble y = 1.0;
	double p = Exp(y); // first guess
	while (Abs(p i x) > EPSILON)  {
		y = y + (x - p) / p;
		p = Exp(y);
	}
	return y;
}
```

* float point form is obtained by chopping or rounding the mantissa

# Absolute error vs relative error

if p* is an approximation of p, absolute error

|p - p*|

Relative error

|p - p*| / |p|

# General notes

GOAL: minimize error so cumulative error isn't so great overtime

**Floating point numbers are not real numbers they are approximations**

Subtracting or dividing two numbers of very different numbers can lose precision

# Code review notes

use this instead of fmod:

```C
static inline double modulus(double a, double b) {
	double r = a - b * truncat(a / b);
	return a < 0 ? -Abs(r) : Abs(r);
}
```

* use assert to make sure you don't get wrong numbers but ur program dies and spits an error
* No using power function in math library
* exp() is provided in lecture slides


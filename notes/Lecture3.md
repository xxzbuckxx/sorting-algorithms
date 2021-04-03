# Lecture 2

## What is RSA?

* Public Key cryptography
	* A public key and a private key 
* Choose very large prime numbers p & q 
	* n = p x q 
	* e is a random prime
	* e x d ≡ 1 (mod)(p - 1)(q - 1)


## On the Nature of Numbers

* 1, 3, 5, 11 are representations of numbers
	* cannot hold a number 
* Numbers exist independently of their representation 
	* many ways to write the same number 
* We use base 10 because we have 10 fingers 
	* Babylonians used base 60 that is why 60 minutes seconds 

**Computers do arithmetic in finite fields**

any number can be written as a polynomial

## How to specify an integer in C

* char
* unsigned char
* int -> native word size 
* unisned int

<stdint.h>

uses fixed bit sizes for ints

## Tip to remember

* Program should be easy to read
* And portable

## Arithmetic in a Finite Field

i + 'i = n

twos complement arithmetic

## FLoating Point Numbers

* Real Numbers are continuous
* uncountably infinite
* Floating Point numbers are an approximation:
	* float is 32 bits
	* double is 64 bits
	* long double is 128 bits

0.1 cannot be represented exactly in floating point

_But is is close enough_

## Random Numbers

* computers can't be random, just pseudo-random
	* advantage of repeatability
	* disadvantage of predictability
* Mersenne Twister
	* State of teh art pseudorandom number generator 

## Operators

* Mod only works on positive integers

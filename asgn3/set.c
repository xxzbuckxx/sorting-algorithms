#include "set.h"

//
// Creates an empty set
//
// Function taken from Professor Darrell Long
//
Set set_empty(void) {
    return 0x00000000; // Empty set is 0s for each bit.
}

//
// Returns value of set element x
//
// s: set to check
// x: index of element to check
// Function taken from Professor Darrel Long
//
bool set_member(Set s, int x) {
    return s & (1 << (x % SET_CAPACITY));
}

//
// Sets value of set element x to true
//
// s: set to update
// x: index of element to update
// Function taken from Professor Darrel Long
//
Set set_insert(Set s, int x) {
    return s | (1 << (x % SET_CAPACITY));
}

//
// Sets value of set element x to false
// s: set to update
// x: index of element to update
// Function taken from Professor Darrel Long
//
Set set_remove(Set s, int x) {
    return s & ~(1 << (x % SET_CAPACITY));
}

//
// Returns union of two sets
//
// s: set to union
// t: set to union
// Function taken from Professor Darrel Long
//
Set set_union(Set s, Set t) {
    return s | t;
}

//
// Returns intersection of two sets
//
// s: set to intersect
// t: set to intersect
// Function taken from Professor Darrel Long
//
Set set_intersect(Set s, Set t) {
    return s & t;
}

//
// Returns difference of two sets
//
// s: set to difference
// t: set to difference
// Function taken from Professor Darrel Long
//
Set set_difference(Set s, Set t) {
    return s & ~t;
}

//
// Return complement of a set
//
// s: set to complement
// Function taken from Professor Darrel Long
Set set_complement(Set s) {
    return ~s;
}

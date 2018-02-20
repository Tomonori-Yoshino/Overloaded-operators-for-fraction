/**
 * @file    gcd.cpp
 * @brief   Includes the implementation of gcd function.
 *
 * @author  Tomonori Yoshino
 * @date    Saturday, Feb 17
 */
#include "gcd.h"
#include "gcd.h"

int gcd(int a, int b) {
    int remainder;
    
    while (b != 0) {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    
    return a;
}




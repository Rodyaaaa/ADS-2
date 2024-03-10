// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    } 
    double pow = 1;
    for (uint16_t i = 0; i < n; i++) {
        pow *= value;
    }
    return pow;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    uint64_t fac = 1;
    for (uint16_t i = 1; i <= n; i++) {
        fac *= i;
    }
    return fac;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n); 
}

double expn(double x, uint16_t count) {
    double exp = 1;
    for (uint16_t i = 1; i <= count; i++) {
        exp += calcItem(x, i);
    }
    return exp;
}

double sinn(double x, uint16_t count) {
    double sin = 0;
    bool even = false;
    for (uint16_t i = 1; i < 2 * count; i += 2) {
        if (even) {
            sin -= calcItem(x, i);
        }
        else {
            sin += calcItem(x, i);
        } 
        even = !even;
    }
    return sin;
}

double cosn(double x, uint16_t count) {
    double cos = 1;
    bool even = true; 
    for (uint16_t i = 2; i < 2 * count; i += 2) {
        if (even) {
            cos -= calcItem(x, i);
        }
        else {
            cos += calcItem(x, i);
        }
        even = !even;
    }
    return cos;
}

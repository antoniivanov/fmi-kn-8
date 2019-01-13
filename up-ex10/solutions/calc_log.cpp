#include <iostream>

double log2(double n) {
    if (n < 0.0000001) {
        return 0;
    }
    return 1 + log2(n/2);
}
//
// Created by zipionlive on 26/11/24.
//

#include "mathTools.h"

int pow(const int base, const int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
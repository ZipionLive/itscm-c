//
// Created by zipionlive on 7/09/24.
//

#include "mathTools.h"

double power(const double n, const int p) {
    if (p == 0) {
        return 1;
    }

    double result = n > 0 ? n : 1;

    if (p > 1) {
        // Positive power
        for (int i = 0; i < p; i++) {
            result *= n;
        }
    } else {
        // Negative power
        for (int i = 0; i >= p; i--) {
            result /= n;
        }
    }

    return result;
}
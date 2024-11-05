//
// Created by zipionlive on 5/11/24.
//

#include "random.h"

#include <stdlib.h>
#include <time.h>

int powTen(const u_int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 10;
    }
    return result;
}

int genRandomInt(const int max, const int seed)
{
    srand(time(NULL) + seed);
    return rand() % max;
}

float genRandomFloat(const int max, const int decimals, const int seed)
{
    srand(time(NULL) + seed);
    const int multiplier = powTen(decimals);
    const int irand = genRandomInt((max * multiplier), seed);
    return (float)irand / (float)multiplier;
}
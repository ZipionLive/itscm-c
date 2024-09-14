//
// Created by zipionlive on 14/09/24.
//

#include "randomGenerator.h"
#include <stdlib.h>
#include <time.h>


int genNumber(const int max, const int seed) {
    srand(time(NULL) + seed);
    return rand() % (max + 1);
}

int *genTab(const int size) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumber(100, i);
    }

    return tab;
}
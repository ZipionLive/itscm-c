//
// Created by zipionlive on 14/09/24.
//

#include "randomGenerator.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int genNumberMax(const int max, const int seed) {
    srand(time(NULL) + seed);
    return rand() % (max + 1);
}

int genNumberMinMax(const int min, const int max, const int seed) {
    srand(time(NULL) + seed);
    int randMax = max - min;
    return (rand() % (randMax + 1)) + min;
}

int *genTabMax(const int size, const int max) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumberMax(max, i);
    }

    return tab;
}

int *genTabMinMax(const int size, const int min, const int max) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumberMinMax(min, max, i);
    }

    return tab;
}

int *genTabMaxVerbose(const int size, const int max) {
    int *tab = genTabMax(size, max);

    printf("Array generated:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: value = %d | address = %p\n", i, tab[i], &tab[i]);
    }

    return tab;
}

int *genTabMinMaxVerbose(const int size, const int min, const int max) {
    int *tab = genTabMinMax(size, min, max);

    printf("Array generated:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: value = %d | address = %p\n", i, tab[i], &tab[i]);
    }

    return tab;
}
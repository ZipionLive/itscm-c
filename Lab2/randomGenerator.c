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

int *genTabMax(const int size, const int max, const int seed) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumberMax(max, i + seed);
    }

    return tab;
}

int *genTabMinMax(const int size, const int min, const int max, const int seed) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumberMinMax(min, max, i + seed) + min;
    }

    return tab;
}

int *genTabMaxVerbose(const int size, const int max, const int seed) {
    int *tab = genTabMax(size, max, seed);

    printf("Array generated:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: value = %d | address = %p\n", i, tab[i], &tab[i]);
    }

    return tab;
}

int *genTabMinMaxVerbose(const int size, const int min, const int max, const int seed) {
    int *tab = genTabMinMax(size, min, max, seed);

    printf("Array generated:\n");
    for (int i = 0; i < size; i++) {
        printf("Index %d: value = %d | address = %p\n", i, tab[i], &tab[i]);
    }

    return tab;
}

int **genTab2dMax(const int lines, const int columns, const int max, const int seed) {
    int **tab = malloc(lines * sizeof(int*));
    for (int i = 0; i < lines; i++) {
        tab[i] = malloc(sizeof(int) * columns);
        for (int j = 0; j < columns; j++) {
            tab[i][j] = genNumberMax(max, i + j + seed);
        }
    }
    return tab;
}

int **genTab2dMinMax(const int lines, const int columns, const int min, const int max, const int seed) {
    int **tab = malloc(lines * sizeof(int*));
    for (int i = 0; i < lines; i++) {
        tab[i] = malloc(sizeof(int) * columns);
        for (int j = 0; j < columns; j++) {
            tab[i][j] = genNumberMinMax(min, max, i + j + seed);
        }
    }
    return tab;
}
//
// Created by zipionlive on 19/09/24.
//

#include "copyTab.h"

#include <stdlib.h>

int *copyTab(int *tab, const int size) {
    int *newTab = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        newTab[i] = tab[i];
    }
    return newTab;
}

int *copyTabOdd(int *tab, const int size, int *oddSize) {
    oddSize[0] = 0;

    for (int i = 0; i < size; i++) {
        if (tab[i] % 2 == 1) {
            oddSize[0]++;
        }
    }

    if (oddSize[0] == 0) {
        return NULL;
    }

    int *odds = malloc(sizeof(int) * oddSize[0]);
    {
        int j = 0;
        for (int i = 0; i < size && j < oddSize[0]; i++) {
            if (tab[i] % 2 == 1) {
                odds[j] = tab[i];
                j++;
            }
        }
    }

    return odds;
}

int *copyTabEven(int *tab, const int size, int *evenSize) {
    evenSize[0] = 0;

    for (int i = 0; i < size; i++) {
        if (tab[i] % 2 == 0) {
            evenSize[0]++;
        }
    }

    if (evenSize[0] == 0) {
        return NULL;
    }

    int *evens = malloc(sizeof(int) * evenSize[0]);
    {
        int j = 0;
        for (int i = 0; i < size && j < evenSize[0]; i++) {
            if (tab[i] % 2 == 0) {
                evens[j] = tab[i];
                j++;
            }
        }
    }

    return evens;
}
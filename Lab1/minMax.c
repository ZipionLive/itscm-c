//
// Created by zipionlive on 14/09/24.
//

#include "minMax.h"
#include <stdio.h>
#include <limits.h>

void showMin(int *tab, int size) {
    int min = INT_MAX;

    for (int i = 0; i < size; i++) {
        min = tab[i] < min ? tab[i] : min;
    }

    printf("Minimum value is: %d\n", min);
}

void showMax(int *tab, int size) {
    int max = INT_MIN;

    for (int i = 0; i < size; i++) {
        max = tab[i] > max ? tab[i] : max;
    }

    printf("Maximum value is: %d\n", max);
}

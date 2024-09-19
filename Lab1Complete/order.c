//
// Created by zipionlive on 19/09/24.
//

#include "copyTab.h"
#include "order.h"
#include "tabSwitch.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void orderAscending(int *tab, const int size) {
    int *copy = copyTab(tab, size);
    int iterations = 0;

    for (int i = 0; i < size; i++) {
        int min = INT_MAX;
        int indexOfMin = -1;

        for (int j = 0; j < size; j++) {
            if (copy[j] < min) {
                min = copy[j];
                indexOfMin = j;
            }

            iterations++;
        }

        copy[indexOfMin] = INT_MAX;
        tab[i] = min;
    }

    printf("Tab sorted in %d iterations.\n", iterations);
    free(copy);
}

void orderAscendingBubble(int *tab, const int size) {
    int didSwitch;
    int iterations = 0;

    do {
        didSwitch = 0;
        for (int i = 0; i < size - 1; i++) {
            if (tab[i] > tab[i + 1]) {
                tabSwitch(tab, i, i + 1);
                didSwitch = 1;
            }

            iterations++;
        }
    } while (didSwitch == 1);

    printf("Tab sorted in %d iterations.\n", iterations);
}

void orderDescending(int *tab, int size) {
    int *copy = copyTab(tab, size);
    int iterations = 0;

    for (int i = 0; i < size; i++) {
        int max = INT_MIN;
        int indexOfMax = -1;

        for (int j = 0; j < size; j++) {
            if (copy[j] > max) {
                max = copy[j];
                indexOfMax = j;
            }

            iterations++;
        }

        copy[indexOfMax] = INT_MIN;
        tab[i] = max;
    }

    printf("Tab sorted in %d iterations.\n", iterations);
    free(copy);
}

void orderDescendingBubble(int *tab, int size) {
    int didSwitch;
    int iterations = 0;

    do {
        didSwitch = 0;
        for (int i = 0; i < size - 1; i++) {
            if (tab[i] < tab[i + 1]) {
                tabSwitch(tab, i, i + 1);
                didSwitch = 1;
            }

            iterations++;
        }
    } while (didSwitch == 1);

    printf("Tab sorted in %d iterations.\n", iterations);
}
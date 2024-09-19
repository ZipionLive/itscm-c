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

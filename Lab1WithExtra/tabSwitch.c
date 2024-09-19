//
// Created by zipionlive on 19/09/24.
//

#include "tabSwitch.h"

void tabSwitch(int *tab, const int indexA, const int indexB) {
    const int buffer = tab[indexA];
    tab[indexA] = tab[indexB];
    tab[indexB] = buffer;
}
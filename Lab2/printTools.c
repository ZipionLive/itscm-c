//
// Created by zipionlive on 29/09/24.
//

#include <stdio.h>
#include "printTools.h"

void printTab(const int *tab, const int size) {
    if (tab == NULL) {
        printf("Error: tab is NULL\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d]", tab[i]);
    }

    printf("\n");
}

void printTab2d(const int **tab, const int lines, const int columns) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            printf("[%d]", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//
// Created by zipionlive on 29/09/24.
//

#include "arrayTools.h"

#include <stdlib.h>

int *diffTab(int *tab1, const int size1, int *tab2, const int size2, int *sizeResult) {
    int j = 0;
    int *result = NULL;

    if (size1 > size2) {
        result = malloc(size2 * sizeof(int));
        for (int i = 0; i < size2; i++) {
            const int sub = tab1[i] - tab2[i];
            if (sub > 0) {
                result[j] = sub;
                j++;
            }
        }
        for (int i = size2; i < size1; i++) {
            result[j] = tab1[i];
            j++;
        }
    } else {
        result = malloc(size1 * sizeof(int));
        for (int i = 0; i < size1; i++) {
            const int sub = tab1[i] - tab2[i];
            if (sub > 0) {
                result[j] = sub;
                j++;
            }
        }
        for (int i = size1; i < size2; i++) {
            result[j] = tab2[i];
            j++;
        }
    }
    realloc(result, j * sizeof(int));
    *sizeResult = j;

    return result;
}

int *flattenTab(int **tab, const int lines, const int columns, int *sizeResult) {
    int *result = malloc(lines * columns * sizeof(int));
    int idx = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            result[idx] = tab[i][j];
            idx++;
        }
    }

    *sizeResult = idx;
    return result;
}

int **mergeTab2d(int *tab1, int *tab2, const int size) {
    int **result = malloc(2 * sizeof(int*));
    result[0] = malloc(size * sizeof(int));
    result[1] = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        result[0][i] = tab1[i];
        result[1][i] = tab2[i];
    }

    return result;
}

int **mergeTab2dAlt(int *tab1, const int size1, int *tab2, const int size2, int *sizeResult) {
    *sizeResult = size1 >= size2 ? size1 : size2;
    int **result = malloc(2 * sizeof(int*));
    result[0] = malloc(*sizeResult * sizeof(int));
    result[1] = malloc(*sizeResult * sizeof(int));

    for (int i = 0; i < *sizeResult; i++) {
        result[0][i] = i < size1 ? tab1[i] : 0;
        result[1][i] = i < size2 ? tab2[i] : 0;
    }

    return result;
}

void freeTab2d(int **tab, const int lines) {
    for (int i = 0; i < lines; i++) {
        free(tab[i]);
    }
    free(tab);
}
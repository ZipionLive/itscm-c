#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "randomGenerator.h"

int *diffTab(int *tab1, int size1, int *tab2, int size2, int *sizeResult);
void printTab(const int *tab, int size);
void printTab2d(const int **tab, int lines, int columns);
void freeTab2d(int **tab2d, int lines);
int *flattenTab(int **tab, int lines, int columns, int *sizeResult);

int main(void) {
    int s1 = 8, s2 = 10, s3 = 0, seed = time(NULL);
    int *tab1 = genTabMax(10, 100, seed % 10);
    int *tab2 = genTabMax(8, 100, seed % 100);
    int *tab3 = diffTab(tab1, 10, tab2, 8, &s3);
    printTab(tab1, s1);
    printTab(tab2, s2);
    printTab(tab3, s3);
    free(tab1);
    free(tab2);
    free(tab3);
    int **tab2d = genTab2dMax(10, 10, 1000, seed % 1000);
    printTab2d(tab2d, 10, 10);
    freeTab2d(tab2d, 10);
    int **tab2d2 = genTab2dMinMax(10, 10, 1000, 2000, seed % 1000);
    printTab2d(tab2d2, 5, 5);
    int flatSize = 0;
    int *flat = flattenTab(tab2d2, 5, 5, &flatSize);
    printTab(flat, flatSize);
    freeTab2d(tab2d2, 10);
    free(flat);
    return 0;
}

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

int *diffTab(int *tab1, int size1, int *tab2, int size2, int *sizeResult) {
    int j = 0;
    int *result = NULL;

    if (size1 > size2) {
        result = malloc(size2 * sizeof(int));
        for (int i = 0; i < size2; i++) {
            int sub = tab1[i] - tab2[i];
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
            int sub = tab1[i] - tab2[i];
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

int *flattenTab(int **tab2d, const int lines, const int columns, int *sizeResult) {
    int *result = malloc(lines * columns * sizeof(int));
    int idx = 0;

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            result[idx] = tab2d[i][j];
            idx++;
        }
    }

    *sizeResult = idx;
    return result;
}

void freeTab2d(int **tab2d, const int lines) {
    for (int i = 0; i < lines; i++) {
        free(tab2d[i]);
    }
    free(tab2d);
}
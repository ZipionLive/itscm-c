#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arrayTools.h"
#include "printTools.h"
#include "randomGenerator.h"

int main(void) {
    const int s1 = 8;
    const int s2 = 10;
    int s3 = 0;
    const int seed = time(NULL);

    int *tab1 = genTabMax(s1, 100, seed % 10);
    int *tab2 = genTabMax(s2, 100, seed % 100);
    int *tab3 = diffTab(tab1, s1, tab2, s2, &s3);

    printTab(tab1, s1);
    printTab(tab2, s2);
    printTab(tab3, s3);

    free(tab1);
    free(tab2);
    free(tab3);

    int **tab2d = genTab2dMax(s1, s2, 1000, seed);
    printTab2d(tab2d, s1, s2);
    freeTab2d(tab2d, s1);

    int **tab2d2 = genTab2dMinMax(s1, s2, 1000, 2000, seed);
    printTab2d(tab2d2, 5, 5);

    int flatSize = 0;
    int *flat = flattenTab(tab2d2, 5, 5, &flatSize);
    printTab(flat, flatSize);

    freeTab2d(tab2d2, s1);
    free(flat);

    int *tab4 = genTabMax(s1, 100, seed + 1);
    int *tab5 = genTabMax(s1, 100, seed + 2);
    int **merged1 = mergeTab2d(tab4, tab5, s1);
    printf("tab4 :\n");
    printTab(tab4, s1);
    printf("tab5 :\n");
    printTab(tab5, s1);
    printf("merged1 :\n");
    printTab2d(merged1, 2, s1);

    free(tab4);
    free(tab5);
    freeTab2d(merged1, 2);

    int *tab6 = genTabMax(s1, 100, seed + 3);
    int *tab7 = genTabMax(s2, 100, seed + 4);
    int mergedSize = 0;
    int **merged2 = mergeTab2dAlt(tab6, s1, tab7, s2, &mergedSize);
    printf("tab6 :\n");
    printTab(tab6, s1);
    printf("tab7 :\n");
    printTab(tab7, s2);
    printf("merged2 :\n");
    printTab2d(merged2, 2, mergedSize);

    free(tab6);
    free(tab7);
    freeTab2d(merged2, 2);

    return 0;
}
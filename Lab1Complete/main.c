#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "schoolResults.h"
#include "randomGenerator.h"
#include "minMax.h"

const int tabSize = 5;

int yearsSince1970();
bool isPair(int n);
void printTab(const int *tab, int size);
void callAllFunctions();

int main(void)
{
    callAllFunctions();
    return 0;
}

void callAllFunctions() {
    for (int i = 0; i < 5; i++) {
        const int r = genNumber(100, i);
        showResult(r);
        showResultSwitch(r);
    }

    for (int i = 0; i < 5; i++) {
        const int r = genNumber(100, i);
        printf("random : %d | ", r);
        printf(isPair(r) ? "%d is pair\n" : "%d isn't pair\n", r);
    }

    // proof that time(NULL) returns seconds !
    printf("years since 1970 : %d\n", yearsSince1970());

    int *tab = genTab(tabSize);
    printTab(tab, tabSize);
    int min = getMin(tab, tabSize);
    printf("Minimum value is: %d\n", min);
    int max = getMax(tab, tabSize);
    printf("Maximum value is: %d\n", max);

    free(tab);
}

int yearsSince1970() {
    return time(NULL) / 3600 / 24 / 365;
}

bool isPair(const int n) {
    return n % 2 == 0;
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
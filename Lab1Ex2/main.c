#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int tabSize = 20;

int genNumber(int max, int seed);
int yearsSince1970();
bool isPair(int n);
int *genTab(int size);
void printTab(const int *tab, int size);

int main(void)
{
    for (int i = 1; i < 100; i++) {
        int r = genNumber(100, i);
        printf("random : %d | ", r);
        printf(isPair(r) ? "%d is pair\n" : "%d isn't pair\n", r);
    }

    // proof that time(NULL) returns seconds !
    printf("years since 1970 : %d\n", yearsSince1970());

    int *tab = genTab(tabSize);
    printTab(tab, tabSize);

    free(tab);

    // TEST
    return 0;
}

int genNumber(const int max, const int seed) {
    srand(time(NULL) + seed);
    return rand() % (max + 1);
}

int yearsSince1970() {
    return time(NULL) / 3600 / 24 / 365;
}

bool isPair(const int n) {
    return n % 2 == 0;
}

int *genTab(const int size) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        tab[i] = genNumber(100, i);
    }

    return tab;
}

void printTab(const int *tab, const int size) {
    if (tab == NULL) {
        printf("Error: tab is NULL\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("[%d] ", tab[i]);
    }
    printf("\n");
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "copyTab.h"
#include "schoolResults.h"
#include "randomGenerator.h"
#include "minMax.h"
#include "guess.h"
#include "order.h"

const int tabSize = 10;

int yearsSince1970();
bool isPair(int n);
void printTab(const int *tab, int size);
void callAllFunctions();
int *getUserNumbers(int size);
void getUserNumbersMinMax(int size);
void getNotesAverage(int *notes, int size);

int main(void)
{
    callAllFunctions();
    return 0;
}

void callAllFunctions() {
    for (int i = 0; i < 5; i++) {
        const int r = genNumberMax(100, i);
        showResult(r);
        showResultSwitch(r);
    }

    for (int i = 0; i < 5; i++) {
        const int r = genNumberMax(100, i);
        printf("random : %d | ", r);
        printf(isPair(r) ? "%d is pair\n" : "%d isn't pair\n", r);
    }

    // proof that time(NULL) returns seconds !
    printf("years since 1970 : %d\n", yearsSince1970());

    int *tab = genTabMinMax(tabSize, 100, 200);
    printTab(tab, tabSize);
    int min = getMin(tab, tabSize);
    printf("Minimum value is: %d\n", min);
    int max = getMax(tab, tabSize);
    printf("Maximum value is: %d\n", max);

    free(tab);

    // guessNumber(1);
    // guessLetter(1);
    // getUserNumbersMinMax(3);

    int *tab1 = genTabMax(tabSize, 100);
    int *tab2 = copyTab(tab1, tabSize);
    int *tab3 = copyTab(tab1, tabSize);
    int *tab4 = copyTab(tab1, tabSize);

    printf("Unsorted tab:\n");
    printTab(tab1, tabSize);

    printf("Sorted tab ascending:");
    orderAscending(tab1, tabSize);
    printTab(tab1, tabSize);

    printf("Sorted tab ascending bubble:");
    orderAscendingBubble(tab2, tabSize);
    printTab(tab2, tabSize);

    printf("Sorted tab descending:");
    orderDescending(tab3, tabSize);
    printTab(tab3, tabSize);

    printf("Sorted tab descending bubble:");
    orderDescendingBubble(tab4, tabSize);
    printTab(tab4, tabSize);

    free(tab1);
    free(tab2);
    free(tab3);
    free(tab4);

    int *notes = genTabMax(tabSize, 20);
    printf("Notes:\n");
    printTab(notes, tabSize);
    getNotesAverage(notes, tabSize);

    free(notes);
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

int *getUserNumbers(const int size) {
    int *tab = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        printf("Enter number N°%d out of %d:\n", i + 1, size);
        scanf("%d", &tab[i]);
    }

    return tab;
}

void getUserNumbersMinMax(const int size) {
    int *userNumbers = getUserNumbers(size);

    for (int i = 0; i < size; i++) {
        printf("Enter number N°%d out of %d:\n", i + 1, size);
        scanf("%d", &userNumbers[i]);
    }

    printf("Minimum value is %d and maximum value is %d.\n", getMin(userNumbers, size), getMax(userNumbers, size));
    free(userNumbers);
}

void getNotesAverage(int *notes, const int size) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += notes[i];
    }

    double avg = (double)sum / size;

    printf("Moyenne de %.2f/20 : ", avg);
    if (avg < 10) {
        printf("Refusé\n");
    } else if (avg < 12) {
        printf("Passable\n");
    } else if (avg < 14) {
        printf("Assez bien\n");
    } else if (avg < 16) {
        printf("Bien\n");
    } else {
        printf("Très bien\n");
    }
}
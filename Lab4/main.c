#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "array.h"
#include "random.h"

#define RAND_MAX 1000
#define FLOAT_DECIMALS 3
#define TAB_LINES 3
#define TAB_COLUMNS 5

void showValuesAndAddresses();
void demo2a();
void fun(int *i);
void genAndPrintTab();
void swapAndPrintNumbers();
void swapNum(int *p1, int *p2);
void genAndPrintTab2DByAddress();
void getAndPrint3Tabs();
int **genAndReturn3Tabs(int size1, int size2, int size3, int seed);
void showPointerExpressions();
void addAndPrintPointers();
int *addPointers(int *p1, int *p2);

int main(void)
{
    showValuesAndAddresses();
    demo2a();
    genAndPrintTab();
    swapAndPrintNumbers();
    genAndPrintTab2DByAddress();
    getAndPrint3Tabs();
    showPointerExpressions();
    addAndPrintPointers();
    return 0;
}

// Labo 4.1 ex 1
void showValuesAndAddresses()
{
    printf("\nLab 4.1 ex 1\n");
    float f1 = -45.78f, f2 = 678.89f;
    float *p1 = &f1, *p2 = &f2;
    printf("p1 : address = %p, value = %p, pointed value = %.2f\n", &p1, p1, *p1);
    printf("f1 : address = %p, value = %.2f\n", &f1, f1);
    printf("p2 : address = %p, value = %p, pointed value = %.2f\n", &p2, p2, *p2);
    printf("f2 : address = %p, value = %.2f\n", &f2, f2);
}

// Labo 4.1 ex 2a
// The value pointed by p is incremented, THEN p is incremented.
// Therefore, what will be printed is the next value in the array, not yet incremented
// The output will then be "20 30 40 50"
// Answer : B
void demo2a() {
    printf("\nLab 4.1 ex 2a\n");
    int tab[] = { 10, 20, 30, 40, 50 };
    int i, *p;
    p = tab;
    for (i = 0; i < 4; i++) {
        fun(p++);
        printf("%d ", *p);
    }
    printf("\n");
}

void fun(int *i) {
    *i = *i + 1;
}

// Labo 4.1 ex 2b
// This code would cause a compilation error because, on the 4th line,
// we try to assign an address (&a) to an int variable (p) without casting.
// Answer : D
/*void demo2b()
{
    printf("\nLab 4.1.2b\n");
    int a = 89;
    int p;
    p = &a;
    *(int*)p = 8;
    printf("%d\n", a);
}*/

// Labo 4.1 ex 4
void genAndPrintTab()
{
    printf("\nLab 4.1 ex 4\n");
    float *tab = genTabFloat(TAB_COLUMNS, RAND_MAX, FLOAT_DECIMALS, 0);
    printf("By index :\n");
    printTabFloat(tab, TAB_COLUMNS, true);
    printf("By address :\n");
    printTabFloatByAddress(tab, TAB_COLUMNS, true);
    printf("\n");
    free(tab);
}

// Labo 4.1 ex 5
void swapAndPrintNumbers()
{
    printf("\nLab 4.1 ex 5\n");
    int n1 = 10, n2 = 20;
    int *p1 = &n1, *p2 = &n2;
    printf("*p1 = %d | *p2 = %d\n", *p1, *p2);
    swapNum(p1, p2);
    printf("*p1 = %d | *p2 = %d\n", *p1, *p2);
}

void swapNum(int *p1, int *p2)
{
    const int buffer = *p1;
    *p1 = *p2;
    *p2 = buffer;
}

// Labo 4.1 ex 6
void genAndPrintTab2DByAddress()
{
    printf("\nLab 4.1 ex 6\n");
    int **tab = genTabInt2D(TAB_LINES, TAB_COLUMNS, RAND_MAX, 100);
    printTabInt2DByAddress(tab, TAB_LINES, TAB_COLUMNS, false);
    freeTabInt(tab, TAB_LINES);
}

// Labo 4.2 ex 1
// This procedure causes a runtime error because str2 points to the memory address of str1
// and therefore, freeing str1 also frees str2 and we then try to access deallocated memory
/*void charPointers()
{
    printf("\nLab 4.2 ex 1\n");
    char *str1 = "abcd";
    char *str2 = str1;
    printf("Before free(str1) : *str1 = %c, *str2 = %c", *str1, *str2);
    free(str1);
    printf("After free(str1) : *str2 = %c", *str2);
}*/

// Labo 4.2 ex 2
// There is a way to somehow return 3 arrays : returning a 2D array with 3 lines
// Every line can have a different size
void getAndPrint3Tabs()
{
    printf("\nLab 4.2 ex 2\n");
    const int size1 = 3, size2 = 4, size3 = 5;
    int **tab = genAndReturn3Tabs(size1, size2, size3, 1000);
    for (int i = 0; i < size1; i++)
    {
        printf("[%d] ", tab[0][i]);
    }
    printf("\n");
    for (int i = 0; i < size2; i++)
    {
        printf("[%d] ", tab[1][i]);
    }
    printf("\n");
    for (int i = 0; i < size3; i++)
    {
        printf("[%d] ", tab[2][i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

int **genAndReturn3Tabs(const int size1, const int size2, const int size3, const int seed)
{
    int **tab = malloc(3 * sizeof(int *));
    tab[0] = malloc(size1 * sizeof(int));
    for (int i = 0; i < size1; i++)
    {
        tab[0][i] = genRandomInt(RAND_MAX, seed + i + 1000);
    }
    tab[1] = malloc(size2 * sizeof(int));
    for (int i = 0; i < size2; i++)
    {
        tab[1][i] = genRandomInt(RAND_MAX, seed + i + 2000);
    }
    tab[2] = malloc(size3 * sizeof(int));
    for (int i = 0; i < size3; i++)
    {
        tab[2][i] = genRandomInt(RAND_MAX, seed + i + 3000);
    }
    return tab;
}

// Labo 4.2 ex 3
void showPointerExpressions()
{
    printf("\nLab 4.2 ex 3\n");
    int tab[] = { 16, 24, 56, 12, 21, 45, 19, 80, 93 };
    int *p;
    p = tab;
    printf("tab = %p\n&tab = %p\np = %p\n&p = %p\n\n", tab, &tab, p, &p);
    for (int i = 0; i < 9; i++)
    {
        printf("tab[%d] = %d @ %p\n", i, tab[i], &tab[i]);
    }
    printf("\n");

    printf("a) *p + 5 = %d\n", *p + 5); // 21 => value of tab[0] + 5
    printf("b) *(p + 5) = %d\n", *p + 5); // 45 => value of tab[0 + 5]
    printf("c) &p + 2 = %p\n", &p + 2); // address of p + (2 * 8) (size of a memory address = 8 bytes)
    printf("d) &tab[4] - 2 = %p\n", &tab[4] - 2); // address of tab[2]
    printf("e) tab + 4 = %p\n", tab + 4); // address of tab[4]
    printf("f) &tab[7] - p = %ld\n", &tab[7] - p); // 7
    printf("g) p + (*p - 10) = %p\n", p + (*p - 10)); // address of tab[6]
    printf("h) *(p + *(p + 8) - 90) = %d\n", *(p + *(p + 8) - 90)); // 12 => *(p + 8) = tab[8] = 93 => *(p + 93 - 90) = tab[3]
    printf("i) *(++tab + 1) = compilation error : ++tab not supported\n");
    printf("j) *(tab + 5) * (*(p + 3)) = %d\n", *(tab + 5) * (*(p + 3))); // 540 => tab[5] * tab[3] = 45 * 12
}

// Labo 4.2 ex 4
void addAndPrintPointers()
{
    printf("\nLab 4.2 ex 4\n");
    int a = 100, b = 325;
    int *p1 = &a, *p2 = &b;
    printf("p1 = %p, *p1 = %d, p2 = %p, *p2 = %d\n", p1, *p1, p2, *p2);
    int *sum = addPointers(p1, p2);
    printf("%d + %d = %d\n", *p1, *p2, *sum);
}

int *addPointers(int *p1, int *p2)
{
    int sum = *p1 + *p2;
    int *result = &sum;
    return result;
}
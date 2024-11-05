//
// Created by zipionlive on 5/11/24.
//

#ifndef ARRAY_H
#define ARRAY_H
#include <stdbool.h>

int *genTabInt(int size, int max, int seed);
float *genTabFloat(int size, int max, int decimals, int seed);
int **genTabInt2D(int lines, int columns, int max, int seed);
float **genTabFloat2D(int lines, int columns, int max, int decimals, int seed);
void printTabInt(int *tab, int size, bool showAddress);
void printTabIntByAddress(int *tab, int size, bool showAddress);
void printTabFloat(float *tab, int size, bool showAddress);
void printTabFloatByAddress(float *tab, int size, bool showAddress);
void printTabInt2D(int **tab, int lines, int columns, bool showAddress);
void printTabFloat2D(float **tab, int lines, int columns, bool showAddress);
void printTabInt2DByAddress(int **tab, int lines, int columns, bool showAddress);
void printTabFloat2DByAddress(float **tab, int lines, int columns, bool showAddress);
void freeTabInt(int **tab, int lines);
void freeTabFloat(float **tab, int lines);

#endif //ARRAY_H

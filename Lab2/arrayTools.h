//
// Created by zipionlive on 29/09/24.
//

#ifndef ARRAYTOOLS_H
#define ARRAYTOOLS_H

int *diffTab(int *tab1, int size1, int *tab2, int size2, int *sizeResult);
int *flattenTab(int **tab, int lines, int columns, int *sizeResult);
int **mergeTab2d(int *tab1, int *tab2, int size);
int **mergeTab2dAlt(int *tab1, int size1, int *tab2, int size2, int *sizeResult);
void freeTab2d(int **tab, int lines);

#endif //ARRAYTOOLS_H

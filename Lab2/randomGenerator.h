//
// Created by zipionlive on 14/09/24.
//

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

int genNumberMax(int max, int seed);
int genNumberMinMax(int min, int max, int seed);
int *genTabMax(int size, int max, int seed);
int *genTabMinMax(int size, int min, int max, int seed);
int **genTab2dMax(int lines, int columns, int max, int seed);
int **genTab2dMinMax(int lines, int columns, int min, int max, int seed);
int *genTabMaxVerbose(int size, int max, int seed);
int *genTabMinMaxVerbose(int size, int min, int max, int seed);

#endif //RANDOMGENERATOR_H

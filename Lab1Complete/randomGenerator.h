//
// Created by zipionlive on 14/09/24.
//

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

int genNumberMax(int max, int seed);
int genNumberMinMax(int min, int max, int seed);
int *genTabMax(int size, int max);
int *genTabMinMax(int size, int min, int max);
int *genTabMaxVerbose(int size, int max);
int *genTabMinMaxVerbose(int size, int min, int max);

#endif //RANDOMGENERATOR_H

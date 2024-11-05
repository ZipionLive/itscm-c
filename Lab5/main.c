#include <stdio.h>
#include <stdlib.h>

#include "bitOperations.h"

int main(void)
{
    printf("\nLab 5 ex 1\n");
    const int in1 = 16;
    const int out1 = bitInvert(in1);
    printf("in1: %d, out1: %d\n", in1, out1);
    printf("\nLab 5 ex 2\n");
    const int in2a = 23, in2b = 4;
    const int out2 = bitXor(in2a, in2b);
    printf("in2a: %d, in2b: %d, out2: %d\n", in2a, in2b, out2);
    printf("\nLab 5 ex 3\n");
    int in3a = 2, in3b = 5;
    printf("in3a: %d, in3b: %d\n", in3a, in3b);
    bitSwap(&in3a, &in3b);
    printf("in3a: %d, in3b: %d\n", in3a, in3b);
    printf("\nLab 5 ex 4\n");
    const int in4 = 192;
    bitCount(in4);
    printf("\nLab 5 ex 5\n");
    const int decIn = 456123;
    decToBinProc(decIn);
    printf("\nLab 5 ex 6\n");
    char *bin = decToBinFct(decIn);
    printf("%d = %s\n", decIn, bin);
    printf("\nLab 5 ex 7\n");
    int decOut = binToDec(bin);
    printf("%s = %d\n", bin, decOut);
    free(bin);
    return 0;
}

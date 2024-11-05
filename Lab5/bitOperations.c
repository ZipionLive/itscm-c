//
// Created by zipionlive on 5/11/24.
//

#include "bitOperations.h"

#include <stdio.h>
#include <stdlib.h>

int pow2(int exponent);

int bitInvert(const int num)
{
    return ~num;
}

int bitXor(const int num1, const int num2)
{
    return num1 ^ num2;
}

void bitSwap(int *num1, int *num2)
{
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

void bitCount(const int num)
{
    int val = num;
    int ones = 0;
    const int bits = sizeof(int) * 8; // size in bytes of an integer multiplied by the number of bits in a byte

    for (int i = 0; i < bits; i++)
    {
        ones += val & 1 ? 1 : 0;
        val >>= 1; // bit shift to the right
    }

    printf("There are %d ones and %d zeroes in %d\n", ones, bits - ones, num);
}

void decToBinProc(const int num)
{
    const int bits = sizeof(int) * 8; // size in bytes of an integer multiplied by the number of bits in a byte

    printf("%d = ", num);

    for (int i = bits - 1; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
        printf(i % 4 == 0 && i != 0 ? " " : ""); // adding a space every 4 bits for readability;
    }

    printf("\n");
}

char *decToBinFct(const int num)
{
    const int bits = sizeof(int) * 8; // size in bytes of an integer multiplied by the number of bits in a byte
    char *result = malloc((bits + (bits / 4) + 1) * sizeof(char));
    int idx = 0;

    for (int i = bits - 1; i >= 0; i--)
    {
        result[idx++] = (num >> i) & 1 ? '1' : '0';
        if (i % 4 == 0 & i != 0)
        {
            result[idx++] = ' ';
        }
    }

    result[idx] = '\0';

    return result;
}

int binToDec(char *bin)
{
    int result = 0;
    int exponent = (sizeof(int) * 8) - 1;
    int idx = 0;

    while (bin[idx] != '\0')
    {
        if (bin[idx] != ' ')
        {
            result += bin[idx] == '1' ? pow2(exponent) : 0;
            exponent--;
        }
        idx++;
    }

    return result;
}

int pow2(const int exponent)
{
    int result = 1;
    for (int i = 0; i < exponent; i++)
    {
        result *= 2;
    }
    return result;
}
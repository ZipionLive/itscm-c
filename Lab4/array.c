//
// Created by zipionlive on 5/11/24.
//

#include "array.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "random.h"


int *genTabInt(const int size, const int max, const int seed)
{
    int *tab = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        tab[i] = genRandomInt(max, seed + i);
    }
    return tab;
}

float *genTabFloat(const int size, const int max, const int decimals, const int seed)
{
    float *tab = malloc(sizeof(float) * size);
    for (int i = 0; i < size; i++)
    {
        tab[i] = genRandomFloat(max, decimals, seed + i);
    }
    return tab;
}

int **genTabInt2D(const int lines, const int columns, const int max, const int seed)
{
    int **tab = malloc(sizeof(int*) * lines);
    for (int i = 0; i < lines; i++)
    {
        tab[i] = genTabInt(columns, max, seed + i * columns);
    }
    return tab;
}

float **genTabFloat2D(const int lines, const int columns, const int max, const int decimals, const int seed)
{
    float **tab = malloc(sizeof(float*) * lines);
    for (int i = 0; i < lines; i++ )
    {
        tab[i] = genTabFloat(columns, max, decimals, seed + i * columns);
    }
    return tab;
}

void printTabInt(int *tab, const int size, const bool showAddress)
{
    for (int i = 0; i < size; i++)
    {
        if (showAddress)
        {
            printf("[%p | %d] ", &tab[i], tab[i]);
        }
        else
        {
            printf("[%d] ", tab[i]);
        }

    }
    printf("\n");
}

void printTabIntByAddress(int *tab, const int size, const bool showAddress)
{
    for (int i = 0; i < size; i++)
    {
        if (showAddress)
        {
            printf("[%p | %d] ", tab + i, *(tab + i));
        }
        else
        {
            printf("[%d] ", *(tab + i));
        }
    }
    printf("\n");
}

void printTabFloat(float *tab, const int size, const bool showAddress)
{
    for (int i = 0; i < size; i++)
    {
        if (showAddress)
        {
            printf("[%p | %.3f] ", &tab[i], tab[i]);
        }
        else
        {
            printf("[%.3f] ", tab[i]);
        }
    }
    printf("\n");
}

void printTabFloatByAddress(float *tab, const int size, const bool showAddress)
{
    for (int i = 0; i < size; i++)
    {
        if (showAddress)
        {
            printf("[%p | %.3f] ", tab + i, *(tab + i));
        }
        else
        {
            printf("[%.3f] ", *(tab + i));
        }
    }
    printf("\n");
}
void printTabInt2D(int **tab, const int lines, const int columns, const bool showAddress)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (showAddress)
            {
                printf("[%p | %d] ", &tab[i][j], tab[i][j]);
            }
            else
            {
                printf("[%d] ", tab[i][j]);
            }
        }
        printf("\n");
    }
}

void printTabFloat2D(float **tab, const int lines, const int columns, const bool showAddress)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (showAddress)
            {
                printf("[%p | %.3f] ", &tab[i][j], tab[i][j]);
            }
            else
            {
                printf("[%.3f] ", tab[i][j]);
            }
        }
        printf("\n");
    }
}

void printTabInt2DByAddress(int **tab, const int lines, const int columns, const bool showAddress)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (showAddress)
            {
                printf("[%p | %d] ", *(tab + i) + j, *(*(tab + i) + j));
            }
            else
            {
                printf("[%d] ", *(*(tab + i) + j));
            }
        }
        printf("\n");
    }
}

void printTabFloat2DByAddress(float **tab, const int lines, const int columns, const bool showAddress)
{
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (showAddress)
            {
                printf("[%p | %.3f] ", *(tab + i) + j, *(*(tab + i) + j));
            }
            else
            {
                printf("[%.3f] ", *(*(tab + i) + j));
            }
        }
        printf("\n");
    }
}

void freeTabInt(int **tab, const int lines)
{
    for (int i = 0; i < lines; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

void freeTabFloat(float **tab, const int lines)
{
    for (int i = 0; i < lines; i++)
    {
        free(tab[i]);
    }
    free(tab);
}
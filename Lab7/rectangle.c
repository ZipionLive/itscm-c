//
// Created by zipionlive on 19/11/24.
//

#include "rectangle.h"

#include <stdio.h>
#include <stdlib.h>

#include "stringTools.h"
#include "userInput.h"

RECTANGLE promptRectangle() {
    RECTANGLE rect;

    rect.width = -1;
    do {
        const char *widthStr = getUserInput("Please enter rectangle width: ", 10);
        rect.width = stringToInt(widthStr);
    } while (rect.width == -1);

    rect.height = -1;
    do {
        const char *heightStr = getUserInput("Please enter rectangle height: ", 10);
        rect.height = stringToInt(heightStr);
    } while (rect.height == -1);

    return rect;
}

RECTANGLE *promptRectangles(const int count) {
    RECTANGLE *rectangles = malloc(sizeof(RECTANGLE) * count);

    for (int i = 0; i < count; i++) {
        printf("\nAdding rectangle %d out of %d\n", i + 1, count);
        rectangles[i] = promptRectangle();
    }

    return rectangles;
}

int getRectangleArea(const RECTANGLE rectangle) {
    return rectangle.height * rectangle.width;
}

int *getRectangleAreas(const RECTANGLE *rectangles, const int count) {
    int *areas = malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++) {
        areas[i] = getRectangleArea(rectangles[i]);
    }

    return areas;
}

int getRectanglePerimeter(const RECTANGLE rectangle) {
    return 2 * (rectangle.width + rectangle.height);
}

int *getRectanglePerimeters(const RECTANGLE *rectangles, const int count) {
    int *perimeters = malloc(sizeof(int) * count);

    for (int i = 0; i < count; i++) {
        perimeters[i] = getRectanglePerimeter(rectangles[i]);
    }

    return perimeters;
}
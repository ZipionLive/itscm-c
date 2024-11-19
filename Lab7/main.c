#include <stdio.h>
#include <stdlib.h>

#include "person.h"
#include "rectangle.h"

#define TAB_SIZE 3

int main(void) {
    PERSON *people = promptPeople(TAB_SIZE);
    printPeople(people, TAB_SIZE);
    RECTANGLE *rectangles = promptRectangles(TAB_SIZE);
    int *areas = getRectangleAreas(rectangles, TAB_SIZE);
    int *perimeters = getRectanglePerimeters(rectangles, TAB_SIZE);
    for (int i = 0; i < TAB_SIZE; i++) {
        printf("\nRectangle %d out of %d:\nWidth: %dcm\nHeight: %dcm\nArea: %dcm²\nPerimeter: %dcm\n",
            i,
            TAB_SIZE,
            rectangles[i].width,
            rectangles[i].height,
            areas[i],
            perimeters[i]);
    }
    free(people);
    free(rectangles);
    free(areas);
    free(perimeters);
    return 0;
}

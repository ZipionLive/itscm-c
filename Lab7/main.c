#include <stdio.h>
#include <stdlib.h>

#include "event.h"
#include "person.h"
#include "rectangle.h"

#define TAB_SIZE 1

int main(void) {
    // PERSON *people = promptPeople(TAB_SIZE);
    // printPeople(people, TAB_SIZE);
    // RECTANGLE *rectangles = promptRectangles(TAB_SIZE);
    // int *areas = getRectangleAreas(rectangles, TAB_SIZE);
    // int *perimeters = getRectanglePerimeters(rectangles, TAB_SIZE);
    // for (int i = 0; i < TAB_SIZE; i++) {
    //     printf("\nRectangle %d out of %d:\nWidth: %dcm\nHeight: %dcm\nArea: %dcm²\nPerimeter: %dcm\n",
    //         i,
    //         TAB_SIZE,
    //         rectangles[i].width,
    //         rectangles[i].height,
    //         areas[i],
    //         perimeters[i]);
    // }
    EVENT *events = promptEvents(TAB_SIZE);
    printEvents(events, TAB_SIZE);
    // free(people);
    // free(rectangles);
    // free(areas);
    // free(perimeters);
    free(events);
    return 0;
}

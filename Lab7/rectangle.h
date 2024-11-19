//
// Created by zipionlive on 19/11/24.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct rectangle {
    int width;
    int height;
} RECTANGLE;

RECTANGLE promptRectangle();
RECTANGLE *promptRectangles(int count);
int getRectangleArea(RECTANGLE rectangle);
int *getRectangleAreas(const RECTANGLE *rectangles, int count);
int getRectanglePerimeter(RECTANGLE rectangle);
int *getRectanglePerimeters(const RECTANGLE *rectangles, int count);

#endif //RECTANGLE_H

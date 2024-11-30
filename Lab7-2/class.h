//
// Created by zipionlive on 27/11/24.
//

#ifndef CLASS_H
#define CLASS_H

typedef struct class {
    char *title;
    char *teacher;
    char *room;
} CLASS;

CLASS promptClass();
CLASS *promptClasses(int count);
void printClass(CLASS class);
void printClasses(CLASS *classes, int count);

#endif //CLASS_H

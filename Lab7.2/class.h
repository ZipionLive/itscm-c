//
// Created by zipionlive on 8/12/24.
//

#ifndef CLASS_H
#define CLASS_H

typedef struct class {
    int year;
    char *section;
} CLASS;

CLASS defaultClass();
CLASS promptClass();
void freeClass(CLASS class);

#endif //CLASS_H

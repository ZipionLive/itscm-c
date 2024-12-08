//
// Created by zipionlive on 8/12/24.
//

#include "class.h"

#include <stdlib.h>

#include "userInput.h"

CLASS defaultClass() {
    CLASS c;

    c.year = -1;
    c.section = "";

    return c;
}

CLASS promptClass() {
    CLASS c;

    c.year = getUserInputInt("Enter class year :");
    c.section = getUserInput("Enter class section :");

    return c;
}

void freeClass(const CLASS class) {
    free(class.section);
}

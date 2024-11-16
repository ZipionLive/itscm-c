#include <stdio.h>

#include "person.h"

int main(void) {
    const PERSON p = promptPerson();
    printPerson(p);
    return 0;
}

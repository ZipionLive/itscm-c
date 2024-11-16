//
// Created by zipionlive on 16/11/24.
//

#include "person.h"
#include "userInput.h"
#include "stringTools.h"

#include <stdio.h>

PERSON newPerson(char *name, const int age, const float height) {
    PERSON p;
    p.name = name;
    p.age = age;
    p.height = height;
    return p;
}

PERSON promptPerson() {
    char *name = getUserInput("Enter the person\'s name : ");

    int age = -1;
    do {
        const char *ageStr = getUserInput("Enter the person\'s age : ");
        age = stringToInt(ageStr);
    } while (age == -1);

    float height = -1;
    do {
        const char *heightStr = getUserInput("Enter the person\'s height : ");
        height = stringToFloat(heightStr);
    } while (height == -1);

    return newPerson(name, age, height);
}

void printPerson(PERSON p) {
    printf("Name : %s | age : %d years old | height : %.2fm\n", p.name, p.age, p.height);
}
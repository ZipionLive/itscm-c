//
// Created by zipionlive on 16/11/24.
//

#include "person.h"
#include "userInput.h"
#include "stringTools.h"

#include <stdio.h>
#include <stdlib.h>

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

PERSON *promptPeople(const int count) {
    PERSON *people = malloc(sizeof(PERSON) * count);
    for (int i = 0; i < count; i++) {
        printf("\nAdding person %d out of %d\n", i + 1, count);
        people[i] = promptPerson();
    }
    return people;
}

void printPerson(const PERSON person) {
    printf("Name : %s\nage : %d years old\nheight : %.2fm\n", person.name, person.age, person.height);
}

void printPeople(const PERSON *people, const int count) {
    for (int i = 0; i < count; i++) {
        printf("\nPerson %d out of %d:\n", i + 1, count);
        printPerson(people[i]);
    }
}
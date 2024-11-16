//
// Created by zipionlive on 16/11/24.
//

#ifndef PERSON_H
#define PERSON_H

typedef struct person {
    char *name;
    int age;
    float height;
} PERSON;

PERSON newPerson(char *name, int age, float height);
PERSON promptPerson();
void printPerson(PERSON person);

#endif //PERSON_H

//
// Created by zipionlive on 27/11/24.
//

#include <stdio.h>
#include <stdlib.h>

#include "class.h"
#include "student.h"
#include "userInput.h"

CLASS promptClass() {
    CLASS class;

    class.title = getUserInput("Enter class title : ");
    class.teacher = getUserInput("Enter class teacher : ");
    class.room = getUserInput("Enter class room : ");

    return class;
}

CLASS *promptClasses(const int count) {
    CLASS *classes = malloc(sizeof(CLASS) * count);

    for (int i = 0; i < count; i++) {
        printf("\nAdding class %d out of %d :\n", i + 1, count);
        classes[i] = promptClass();
    }

    return classes;
}

void printClass(const CLASS class) {
    printf("%s\nTeacher : %s\nRoom : %s\n", class.title, class.teacher, class.room);
}

void printClasses(const CLASS *classes, const int count) {
    for (int i = 0; i < count; i++) {
        printf("\nClass %d out of %d :\n", i + 1, count);
        printClass(classes[i]);
    }
}

STUDENT createStudent()
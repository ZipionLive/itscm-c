//
// Created by zipionlive on 8/12/24.
//

#include "student.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stringTools.h"
#include "userInput.h"

void freeParts(char **parts, const int count) {
    for (int i = 0; i < count; i++) {
        free(parts[i]);
    }
    free(parts);
}

STUDENT defaultStudent() {
    STUDENT s;

    s.firstName = "";
    s.lastName = "";
    s.age = -1;
    s.class = defaultClass();
    s.lessonCount = 0;
    s.lessons = NULL;

    return s;
}

void initStudent(STUDENT *student, const char *studentFormat, bool *successOutput) {
    *successOutput = true;

    int partsCount = 0;
    char **parts = splitString(studentFormat, ',', &partsCount);

    if (partsCount != 3) {
        printf("Wrong format for student input. Should be <firstName>,<lastName>,<age>\n");
        *successOutput = false;
        freeParts(parts, partsCount);
        return;
    }

    const int age = stringToInt(parts[2]);

    if (age == -1) {
        printf("Couldn't parse student age.\n");
        *successOutput = false;
        freeParts(parts, partsCount);
        return;
    }

    student->firstName = parts[0];
    student->lastName = parts[1];
    student->age = age;

    freeParts(parts, partsCount);
}

STUDENT promptStudent() {
    STUDENT s;

    bool success;
    do {
        char *studentFormat = getUserInput("Enter student info (format = <firstName>,<lastName>,<age>) :");
        initStudent(&s, studentFormat, &success);
        free(studentFormat);
    } while(success == false);

    s.class = promptClass();
    s.lessonCount = getUserInputInt("Enter number of lessons for student :");
    s.lessons = promptLessons(s.lessonCount);

    return s;
}

STUDENT *promptStudents(const int count) {
    STUDENT *students = malloc(sizeof(STUDENT) * count);

    for (int i = 0; i < count; i++) {
        printf("\nStudent %d out of %d\n :", i + 1, count);
        students[i] = promptStudent();
    }

    return students;
}

void freeStudent(const STUDENT student) {
    free(student.firstName);
    free(student.lastName);
    freeClass(student.class);
    freeLessons(student.lessons, student.lessonCount);
}

void freeStudents(STUDENT *students, const int count) {
    for (int i = 0; i < count; i++) {
        freeStudent(students[i]);
    }
    free(students);
}
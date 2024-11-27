//
// Created by zipionlive on 27/11/24.
//

#include "student.h"

#include <stdio.h>
#include <stdlib.h>

#include "stringTools.h"
#include "userInput.h"

STUDENT promptStudent() {
    STUDENT student;

    student.firstName = getUserInput("Enter the student's first name :", 50);
    student.lastName = getUserInput("Enter the student's last name :", 50);
    student.class = getUserInput("Enter the student's class :", 50);

    student.mathsResult = -1;
    do {
        const char *mathStr = getUserInput("Enter the student's maths result :", 3);
        student.mathsResult = stringToInt(mathStr);
        if (student.mathsResult < 0 || student.mathsResult > 100) {
            printf("Invalid input : %d is out of range.\n Value should be between 0 and 100 included.\n",
                student.mathsResult);
            student.mathsResult = -1;
        }
    } while (student.mathsResult == -1);

    student.programmingResult = -1;
    do {
        const char *progStr = getUserInput("Enter the student's programming result :", 3);
        student.programmingResult = stringToInt(progStr);
        if (student.programmingResult < 0 || student.programmingResult > 100) {
            printf("Invalid input : %d is out of range.\n Value should be between 0 and 100 included.\n",
                student.programmingResult);
        }
    } while (student.programmingResult == -1);

    return student;
}

STUDENT *promptStudents(const int count) {
    STUDENT *students = malloc(sizeof(STUDENT) * count);

    for (int i = 0; i < count; i++) {
        printf("\nAdding student %d out of %d :\n", i + 1, count);
        students[i] = promptStudent();
    }

    return students;
}

void printStudent(const STUDENT student) {
    printf("First name : %s\nLast name : %s\nClass : %s\nMaths result : %d%%\nProgramming result : %d%%\n",
        student.firstName, student.lastName, student.class, student.mathsResult, student.programmingResult);
}

void printStudents(const STUDENT *students, const int count) {
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d out of %d :\n", i + 1, count);
        printStudent(students[i]);
    }
}

STUDENT getFirstInMaths(const STUDENT *students, const int count) {
    int firstIndex = 0,
        firstScore = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].mathsResult > firstScore) {
            firstIndex = i,
            firstScore = students[i].mathsResult;
        }
    }

    return students[firstIndex];
}

STUDENT getFirstInProgramming(const STUDENT *students, const int count) {
    int firstIndex = 0,
        firstScore = 0;

    for (int i = 0; i < count; i++) {
        if (students[i].programmingResult > firstScore) {
            firstIndex = i,
            firstScore = students[i].programmingResult;
        }
    }

    return students[firstIndex];
}

float getMathsAverage(const STUDENT *students, const int count) {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].mathsResult;
    }

    return (float)sum / (float)count;
}

float getProgrammingAverage(const STUDENT *students, const int count) {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += students[i].programmingResult;
    }

    return (float)sum / (float)count;
}
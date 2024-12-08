//
// Created by zipionlive on 8/12/24.
//

#ifndef STUDENT_H
#define STUDENT_H
#include <stdbool.h>

#include "class.h"
#include "lesson.h"

typedef struct student {
    char *firstName;
    char *lastName;
    int age;
    CLASS class;
    int lessonCount;
    LESSON *lessons;
} STUDENT;

STUDENT defaultStudent();
STUDENT createStudent(const char *studentFormat, bool *successOutput);
STUDENT promptStudent();
STUDENT *promptStudents(int count);
void freeStudent(STUDENT student);
void freeStudents(STUDENT *students, int count);

#endif //STUDENT_H

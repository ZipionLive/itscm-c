//
// Created by zipionlive on 27/11/24.
//

#ifndef STUDENT_H
#define STUDENT_H

#include "class.h"

typedef struct student {
    char *firstName;
    char *lastName;
    int age;
    int year;
    char *section;
    int classCount;
    CLASS *classes;
} STUDENT;

STUDENT createStudent(const char *studentInfo, const char *classInfo, int classCount);
STUDENT promptStudent();
STUDENT *promptStudents(int count);
void printStudent(STUDENT student);
void printStudents(const STUDENT *students, int count);
void freeStudent(STUDENT student);

#endif //STUDENT_H

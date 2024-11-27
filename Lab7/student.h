//
// Created by zipionlive on 27/11/24.
//

#ifndef STUDENT_H
#define STUDENT_H

typedef struct student {
    char *firstName;
    char *lastName;
    char *class;
    int mathsResult;
    int programmingResult;
} STUDENT;

STUDENT promptStudent();
STUDENT *promptStudents(int count);
void printStudent(STUDENT student);
void printStudents(const STUDENT *students, int count);
STUDENT getFirstInMaths(const STUDENT *students, int count);
STUDENT getFirstInProgramming(const STUDENT *students, int count);
float getMathsAverage(const STUDENT *students, int count);
float getProgrammingAverage(const STUDENT *students, int count);

#endif //STUDENT_H

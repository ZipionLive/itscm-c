//
// Created by zipionlive on 27/11/24.
//

#include "student.h"

#include <stdio.h>
#include <stdlib.h>

#include "stringTools.h"
#include "userInput.h"

#define STUDENT_INFO_LENGTH 3
#define SECTION_INFO_LENGTH 2
#define SEPARATOR ','

char **promptStudentInfo() {
    while (1) {
        const char *format = getUserInput("Enter student information (format : \"firstName,lastName,age\") : ");
        int size = 0;

        char **result = splitString(format, SEPARATOR, &size);

        if (size != STUDENT_INFO_LENGTH) {
            printf("Invalid input. Please try again with format : \"firstName,lastName,age\".\n");
            free(result);
            continue;
        }

        const int age = stringToInt(result[2]);
        if (age == -1) {
            printf("Invalid input for age. Please try again with format : \"firstName,lastName,age\".\n");
            free(result);
            continue;
        }

        return result;
    }
}

char **promptSectionInfo() {
    while (1) {
        const char *format = getUserInput("Enter section info (format : \"year,sectionName\") : ");
        int size = 0;

        char **result = splitString(format, SEPARATOR, &size);

        if (size != SECTION_INFO_LENGTH) {
            printf("Invalid input. Please try again with format : \"year,sectionName\".\n");
            free(result);
            continue;
        }

        const int year = stringToInt(result[0]);
        if (year == -1) {
            printf("Invalid input for year. Please try again with format : \"year,sectionName\".\n");
            free(result);
            continue;
        }

        return result;
    }
}


//
// Created by zipionlive on 19/11/24.
//

#include <stdlib.h>

#include "date.h"
#include "stringTools.h"
#include "userInput.h"

DATE promptDate() {
    DATE date;

    date.day = -1;
    do {
        const char *dayStr = getUserInput("Enter date's day :", 2);
        date.day = stringToInt(dayStr);
    } while (date.day == -1);

    date.month = -1;
    do {
        const char *monthStr = getUserInput("Enter date's month :", 2);
        date.month = stringToInt(monthStr);
    } while (date.month == -1);

    date.year = -1;
    do {
        const char *yearStr = getUserInput("Enter date's year :", 4);
        date.year = stringToInt(yearStr);
    } while (date.year == -1);

    return date;
}

char *dateToString(const DATE date) {
    const char *day = padNumber(date.day, 2);
    const char *month = padNumber(date.month, 2);
    const char *year = padNumber(date.year, 4);
    char *result = malloc(11 * sizeof(char));

    result[0] = day[0];
    result[1] = day[1];
    result[2] = '/';
    result[3] = month[0];
    result[4] = month[1];
    result[5] = '/';
    result[6] = year[0];
    result[7] = year[1];
    result[8] = year[2];
    result[9] = year[3];
    result[10] = '\0';

    return result;
}
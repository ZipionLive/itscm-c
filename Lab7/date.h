//
// Created by zipionlive on 19/11/24.
//

#ifndef DATE_H
#define DATE_H

typedef struct date {
    int year;
    int month;
    int day;
} DATE;

DATE promptDate();
char *dateToString(DATE date);

#endif //DATE_H

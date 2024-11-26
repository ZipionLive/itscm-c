//
// Created by zipionlive on 26/11/24.
//

#ifndef EVENT_H
#define EVENT_H
#include "date.h"

typedef struct event {
    char *name;
    char *location;
    DATE date;
} EVENT;

EVENT promptEvent();
EVENT *promptEvents(int count);
void printEvent(EVENT event);
void printEvents(const EVENT *events, int count);

#endif //EVENT_H

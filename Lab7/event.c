//
// Created by zipionlive on 26/11/24.
//

#include "event.h"

#include <stdio.h>
#include <stdlib.h>

#include "date.h"
#include "userInput.h"

EVENT promptEvent() {
    EVENT event;

    event.name = getUserInput("Enter event name :", 50);
    event.location = getUserInput("Enter event location :", 50);
    printf("Enter event date :\n");
    event.date = promptDate();

    return event;
}

EVENT *promptEvents(const int count) {
    EVENT *events = malloc(count * sizeof(EVENT));

    for (int i = 0; i < count; i++) {
        printf("Adding event %d out of %d :\n", i + 1, count);
        events[i] = promptEvent();
    }

    return events;
}

void printEvent(const EVENT event) {
    printf("Name : %s\nLocation : %s\nDate : %s\n", event.name, event.location, dateToString(event.date));
}

void printEvents(const EVENT *events, const int count) {
    for (int i = 0; i < count; i++) {
        printf("\nEvent %d out of %d :\n", i + 1, count);
        printEvent(events[i]);
    }
}

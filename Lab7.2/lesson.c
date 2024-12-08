//
// Created by zipionlive on 8/12/24.
//

#include "lesson.h"

#include <stdio.h>
#include <stdlib.h>

#include "userInput.h"

LESSON promptLesson() {
    LESSON l;

    l.title = getUserInput("Enter lesson title :");
    l.teacher = getUserInput("Enter lesson teacher :");
    l.room = getUserInput("Enter lesson room :");

    return l;
}

LESSON *promptLessons(const int count) {
    LESSON *lessons = malloc(sizeof(LESSON) * count);

    for (int i = 0; i < count; i++) {
        printf("\nLesson %d out of %d\n :", i + 1, count);
        lessons[i] = promptLesson();
    }

    return lessons;
}

void freeLesson(const LESSON lesson) {
    free(lesson.title);
    free(lesson.teacher);
    free(lesson.room);
}

void freeLessons(LESSON *lessons, const int count) {
    for (int i = 0; i < count; i++) {
        freeLesson(lessons[i]);
    }
    free(lessons);
}
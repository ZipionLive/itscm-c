//
// Created by zipionlive on 8/12/24.
//

#ifndef LESSON_H
#define LESSON_H

typedef struct lesson {
    char *title;
    char *teacher;
    char *room;
} LESSON;

LESSON promptLesson();
LESSON *promptLessons(int count);
void freeLesson(LESSON lesson);
void freeLessons(LESSON *lessons, int count);

#endif //LESSON_H

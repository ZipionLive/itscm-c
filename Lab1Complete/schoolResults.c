//
// Created by zipionlive on 14/09/24.
//

#include "schoolResults.h"
#include <stdio.h>

void showResult(const int note) {
    if (note >= 0 && note < 50) {
        printf("%d%% : Echec\n", note);
    } else if (note >= 50 && note < 60) {
        printf("%d%% : Satisfaction\n", note);
    } else if (note >= 60 && note < 70) {
        printf("%d%% : Distinction\n", note);
    } else if (note >= 70 && note < 80) {
        printf("%d%% : Grande distinction\n", note);
    } else if (note >= 80 && note < 90) {
        printf("%d%% : Très grande distinction\n", note);
    } else if (note >= 90 && note <= 100) {
        printf("%d%% : La plus grande distinction\n", note);
    } else {
        printf("%d%% : Score impossible\n", note);
    }
}

void showResultSwitch(const int note) {
    if (note > 100 || note < 0) {
        printf("%d%% : Score impossible\n", note);
        return;
    }

    switch (note / 10) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("%d%% : Echec\n", note);
        break;
        case 5:
            printf("%d%% : Satisfaction\n", note);
        break;
        case 6:
            printf("%d%% : Distinction\n", note);
        break;
        case 7:
            printf("%d%% : Grande distinction\n", note);
        break;
        case 8:
            printf("%d%% : Très grande distinction\n", note);
        break;
        default:
            printf("%d%% : La plus grande distinction\n", note);
        break;
    }
}
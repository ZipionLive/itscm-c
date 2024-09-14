#include <stdio.h>
#include <stdlib.h>

void showResult(int note);
void showResultSwitch(int note);

int main(void)
{
    for (int i = -10; i < 110; i+= 5) {
        showResult(i);
        showResultSwitch(i);
    }

    return 0;
}

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
    switch (note) {
        case 0 ... 49:
            printf("%d%% : Echec\n", note);
            break;
        case 50 ... 59:
            printf("%d%% : Satisfaction\n", note);
            break;
        case 60 ... 69:
            printf("%d%% : Distinction\n", note);
            break;
        case 70 ... 79:
            printf("%d%% : Grande distinction\n", note);
            break;
        case 80 ... 89:
            printf("%d%% : Très grande distinction\n", note);
            break;
        case 90 ... 100:
            printf("%d%% : La plus grande distinction\n", note);
            break;
        case default:
            printf("%d%% : Score impossible\n", note);
            break;
    }
}

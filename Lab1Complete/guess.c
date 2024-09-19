//
// Created by zipionlive on 19/09/24.
//

#include "guess.h"
#include "randomGenerator.h"
#include <stdio.h>

int getUserGuess() {
    while (1) {
        printf("\n");
        printf("Please guess a number between 0 and 100: \n");
        int input;
        scanf("%d", &input);

        if (input >= 0 && input <= 100) {
            return input;
        }

        printf("Guess is out of range, try again... \n");
    }
}

int getUserGuessChar() {
    while (1) {
        printf("\n");
        printf("Please guess a letter :\n");
        char input;
        scanf(" %c", &input);

        if (input >= 'a' && input <= 'z') {
            return input - 32;
        }

        if (input >= 'A' && input <= 'Z') {
            return input;
        }
    }
}

void guessNumber(const int playUntilGuessed) {
    const int rnd = genNumberMax(100, -1);
    int rightGuess = 0;
    int guesses = 0;

    do {
        guesses++;

        const int guess = getUserGuess();

        if (guess > rnd) {
            printf("Too high\n");
        } else if (guess < rnd) {
            printf("Too low\n");
        } else {
            printf("Bingo !\n");
            rightGuess = 1;

            if (playUntilGuessed == 1) {
                printf("Number %d found in %d attempts\n", rnd, guesses);
            }
        }
    } while (rightGuess == 0 && playUntilGuessed == 1);
}

void guessLetter(const int playUntilGuessed) {
    const char rnd = genNumberMinMax(65, 90, -2);
    int rightGuess = 0;
    int guesses = 0;

    do {
        guesses++;

        const char guess = getUserGuessChar();

        if (guess > rnd) {
            printf("Too high\n");
        } else if (guess < rnd) {
            printf("Too low\n");
        } else {
            printf("Bingo !\n");
            rightGuess = 1;

            if (playUntilGuessed == 1) {
                printf("Letter %c found in %d attempts\n", rnd, guesses);
            }
        }
    } while (rightGuess == 0 && playUntilGuessed == 1);
}
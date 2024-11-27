//
// Created by zipionlive on 11/11/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringTools.h"
#include "userInput.h"

// Honestly not too proud of this hack :-/
void flushInput() {
    char *buffer = malloc(256);
    fgets(buffer, 256, stdin);
    free(buffer);
}

char *getUserInput(const char *prompt, const int maxLength) {
    const int bufferSize = maxLength + 2; // max length of the prompt + two characters for \n and \0
    char buffer[bufferSize];
    char *userInput = NULL;
    int success = 0;

    while (success == 0) {
        printf("%s ", prompt);
        if (fgets(buffer, bufferSize, stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
            flushInput();
            continue;
        }

        if (getLength(buffer) > maxLength) {
            printf("Input is too long : max length = %d. Please try again.\n", maxLength);
            flushInput();
            continue;
        }

        // Remove the newline character, if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if the input is empty
        if (strlen(buffer) == 0) {
            printf("Input cannot be empty. Please try again.\n");
            continue;
        }

        // Allocate memory for the user input and copy the buffer
        userInput = strdup(buffer);
        if (userInput == NULL) {
            printf("Memory allocation failed. Exiting.\n");
            exit(EXIT_FAILURE);
        }

        success = 1;
    }

    return userInput;
}
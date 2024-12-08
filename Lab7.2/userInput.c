//
// Created by zipionlive on 11/11/24.
//

#include "userInput.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringTools.h"

#define BUFFER_SIZE 512

char *getUserInput(const char *prompt) {
    char buffer[BUFFER_SIZE];
    char *userInput = NULL;
    int success = 0;

    while (success == 0) {
        printf("%s ", prompt);
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input. Please try again.\n");
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

int getUserInputInt(const char *prompt) {
    int result = -1;

    while (result == -1) {
        char *resultStr = getUserInput(prompt);
        result = stringToInt(resultStr);
        free(resultStr);
    }

    return result;
}

//
// Created by zipionlive on 9/11/24.
//

#include "credentials.h"
#include "stringTools.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

#define FORMAT_PARTS 5

USER emptyUser() {
    USER user;
    user.login = NULL;
    user.password = NULL;
    user.firstName = NULL;
    user.lastName = NULL;
    user.age = 0;
    return user;
}

USER getUser(const char *formattedString, const char separator) {
    int sizeOutput;
    char **parts = splitString(formattedString, separator, &sizeOutput);
    if (sizeOutput != FORMAT_PARTS) {
        fprintf(stderr, "Format '%s' does not match expected number of elements.\n", formattedString);
        return emptyUser();
    }

    USER user;
    user.login = parts[0];
    user.password = parts[1];
    user.firstName = parts[2];
    user.lastName = parts[3];
    user.age = stringToInt(parts[4]);

    return user;
}

void printUser(const USER user) {
    if (user.login == NULL) {
        printf("User is NULL, nothing to print...\n");
        return;
    }

    printf("user.login : %s\n", user.login);
    printf("user.password : %s\n", user.password);
    printf("user.firstName : %s\n", user.firstName);
    printf("user.lastName : %s\n", user.lastName);
    printf("user.age : %d\n", user.age);
    printf("\n");
}

int logUser(const char *login, const char *password, const USER *userDb, const int usersCount) {
    for (int i = 0; i < usersCount; i++) {
        USER user = userDb[i];
        if (isEqualString(user.login, login) == 1 && isEqualString(user.password, password) == 1) {
            return 1;
        }
    }

    return 0;
}

void freeUser(const USER user) {
    if (user.login) free(user.login);
    if (user.password) free(user.password);
    if (user.firstName) free(user.firstName);
    if (user.lastName) free(user.lastName);
}
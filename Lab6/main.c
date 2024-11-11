#include <stdio.h>
#include <stdlib.h>

#include "credentials.h"
#include "fileHandling.h"
#include "userInput.h"

#define N_USER 4
#define BUFFER_SIZE 512
#define SEPARATOR ','

const char dbPath[] = "/home/zipionlive/Documents/fsocietydb.txt";

void createDataBase();
USER *readDataBase();
void freeDataBase(USER *userDb);

int main(void) {
    createDataBase();

    USER *userDb = readDataBase();

    for (int i = 0; i < N_USER; i++) {
        printf("User #%d:\n", i + 1);
        printUser(userDb[i]);
    }

    char *login = getUserInput("Enter your login :");
    char *password = getUserInput("Enter your password :");

    if (logUser(login, password, userDb, N_USER)) {
        printf("User \"%s\" successfully logged in !\n", login);
    } else {
        printf("Login failed for user \"%s\".\n", login);
    }

    freeDataBase(userDb);

    deleteFile(dbPath);

    return 0;
}

void createDataBase() {
    char **strUsers = malloc(N_USER * sizeof(char *));
    strUsers[0] = "mr_robot,F#50c13ty,Eliott,Alderson,30\n";
    strUsers[1] = "mrs_robot,C4r3fulM4554cr3,Darlene,Alderson,28\n";
    strUsers[2] = "trenton,St463Fr16ht,Shama,Biswas,25\n";
    strUsers[3] = "mobley,4n63lF1r3,Sunil,Markesh,32\n";

    const int dbError = writeFileByLine(strUsers, N_USER, dbPath);
    if (dbError == 0) {
        printf("Database file successfully created.\n");
    } else {
        printf("Error creating database.\n");
    }

    free(strUsers);
}

USER *readDataBase() {
    USER *result = malloc(N_USER * sizeof(USER));
    char **strUsers = readFileByLine(dbPath, N_USER);

    for (int i = 0; i < N_USER; i++) {
        result[i] = getUser(strUsers[i], SEPARATOR);
    }

    return result;
}

void freeDataBase(USER *userDb) {
    for (int i = 0; i < N_USER; i++) {
        freeUser(userDb[i]);
    }
    free(userDb);
}

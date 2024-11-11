//
// Created by zipionlive on 9/11/24.
//

#ifndef CREDENTIALS_H
#define CREDENTIALS_H

typedef struct user {
    char *login;
    char *password;
    char *firstName;
    char *lastName;
    int age;
} USER;

USER getUser(const char *formattedString, char separator);
void printUser(USER user);
int logUser(const char *login, const char *password, const USER *userDb, const int usersCount);
void freeUser(USER user);

#endif //CREDENTIALS_H

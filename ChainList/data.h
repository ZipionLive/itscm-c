//
// Created by zipionlive on 30/11/24.
//

#ifndef DATA_H
#define DATA_H

typedef struct data {
    int id;
    char *name;
    char *login;
    char *password;
} DATA;

DATA *createData(int id);

#endif //DATA_H

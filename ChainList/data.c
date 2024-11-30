//
// Created by zipionlive on 30/11/24.
//

#include "data.h"

#include <stdlib.h>

#include "userInput.h"

DATA *createData(const int id) {
    DATA *data = malloc(sizeof(DATA));

    data->id = id;
    data->name = getUserInput("Enter name :");
    data->login = getUserInput("Login :");
    data->password = getUserInput("Password :");

    return data;
}

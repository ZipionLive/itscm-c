//
// Created by zipionlive on 30/11/24.
//

#include "dataNode.h"

#include <stdlib.h>

NODE *createNode(DATA *data) {
    NODE *node = malloc(sizeof(NODE));

    node->data = data;
    node->next = NULL;

    return node;
}

void freeNode(NODE *node) {
    free(node->data->name);
    free(node->data->login);
    free(node->data->password);
    free(node->data);
    free(node);
}

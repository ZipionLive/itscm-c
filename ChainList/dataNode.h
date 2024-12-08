//
// Created by zipionlive on 30/11/24.
//

#ifndef DATANODE_H
#define DATANODE_H

#include "data.h"

typedef struct node {
    DATA *data;
    struct node *next;
} NODE;

NODE *createNode(DATA *data);
void freeNode(NODE *node);

#endif //DATANODE_H

//
// Created by zipionlive on 30/11/24.
//

#ifndef DATALIST_H
#define DATALIST_H

#include "dataNode.h"

typedef struct list {
    NODE *first;
} LIST;

LIST *initList();
void addNode(LIST *list, NODE *node);
void printList(const LIST *list);
void freeList(LIST *list);

#endif //DATALIST_H

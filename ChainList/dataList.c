//
// Created by zipionlive on 30/11/24.
//

#include "dataList.h"
#include "dataNode.h"

#include <stdio.h>
#include <stdlib.h>

LIST *initList() {
    LIST *list = malloc(sizeof(LIST));
    list->first = NULL;
    return list;
}

void addNode(LIST *list, NODE *node) {
    if (list->first == NULL) {
        list->first = node;
    } else {
        NODE *current = list->first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void printList(const LIST *list) {
    NODE *current = list->first;
    while (current != NULL) {
        if (current->data != NULL) {
            printf("\nid : %d\nnom : %s\nlogin : %s\npassword : %s\n",
                current->data->id,
                current->data->name,
                current->data->login,
                current->data->password);
        }
        current = current->next;
    }
}

void freeList(LIST *list) {
    NODE *current = list->first;

    while (current != NULL) {
        NODE *next = current->next;
        free(current->data->name);
        free(current->data->login);
        free(current->data->password);
        free(current->data);
        free(current);
        current = next;
    }

    free(list);
}
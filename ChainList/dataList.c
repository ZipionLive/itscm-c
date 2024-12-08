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

void removeNode(LIST *list, const int id) {
    NODE *current = list->first;
    if (current->data->id == id) {
        list->first = current->next;
        freeNode(current);
        printf("\nNode with id %d successfully removed", id);
    }
    else {
        while (current->next != NULL) {
            current = current->next;
            if (current->next->data->id == id) {
                current->next = current->next->next;
                printf("\nNode with id %d successfully removed", id);
            }
        }
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
        freeNode(current);
        current = next;
    }

    free(list);
}
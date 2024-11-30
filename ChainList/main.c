#include <stdio.h>

#include "data.h"
#include "dataNode.h"
#include "dataList.h"

#define COUNT 3

int main(void) {
    LIST *list = initList();

    for (int i = 0; i < COUNT; i++) {
        printf("\nAdd data %d out of %d\n", i + 1, COUNT);
        addNode(list, createNode(createData(i + 1)));
    }

    printList(list);
    freeList(list);

    return 0;
}
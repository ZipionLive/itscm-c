#include <stdio.h>
#include <stdlib.h>

int *proctab();

int main(void)
{
    int stab[3];
    int *dtab = malloc(3 * sizeof(int));
    int *ptab = proctab();

    for (int i = 0; i < 3; i++) {
        stab[i] = i + 1;
        dtab[i] = i + 1;
    }

    printf("&stab[0] = %p\n", &stab[0]);
    printf("&stab    = %p\n", &stab);
    printf("stab     = %p\n", stab);

    printf("&dtab[0] = %p\n", &dtab[0]);
    printf("&dtab    = %p\n", &dtab);
    printf("dtab     = %p\n", dtab);

    printf("&ptab[0] = %p\n", &ptab[0]);
    printf("&ptab    = %p\n", &ptab);
    printf("ptab     = %p\n", ptab);

    for (int i = 0; i < 3; i++) {
        printf("stab[%d] = [%d]\n", i, stab[i]);
        printf("dtab[%d] = [%d]\n", i, dtab[i]);
        printf("ptab[%d] = [%d]\n", i, ptab[i]);
    }

    return 0;
}

int *proctab() {
    int *ptab = malloc(3 * sizeof(int));

    for (int i = 0; i < 3; i++) {
        ptab[i] = i + 1;
    }

    return ptab;
}
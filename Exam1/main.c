#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABSIZE 25000
#define BUFFERSIZE 1024
#define RANDMAX 1000000

void fillTabAndShowEvens();
void countCharacters();
char *concat(const char *s1, const char *s2);

int main(void) {
    fillTabAndShowEvens();
    countCharacters();
    char *s1 = "abc";
    char *s2 = "def";
    char *concatenated = concat(s1, s2);
    printf("%s\n", concatenated);
    free(concatenated);
    return 0;
}

void fillTabAndShowEvens() {
    int *tab = malloc(TABSIZE * sizeof(int));

    if (tab == NULL) {
        printf("Failed to allocate memory for tab.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TABSIZE; i++) {
        srand(time(NULL) + i);
        tab[i] = rand() % RANDMAX;
    }
    for (int i = 0; i < TABSIZE; i++) {
        if (tab[i] % 2 == 0) {
            printf("[%d]", tab[i]);
        }
    }
    printf("\n");
    free(tab);
}

void countCharacters() {
    const char excluded[] = { ' ', '.', ',', '-' };
    char buffer[BUFFERSIZE];
    printf("Enter a string :");
    fgets(buffer, BUFFERSIZE, stdin);
    int i =0, count = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != '\r') {
        int isExcluded = 0;
        for (int j = 0; j < 4; j++) {
            if (buffer[i] == excluded[j]) {
                isExcluded = 1;
            }
        }
        count += isExcluded == 0 ? 1 : 0;
        i++;
    }
    printf("The string \"%s\" contains %d characters\n", buffer, count);
}

char *concat(const char *s1, const char *s2) {
    int l1 = 0, l2 = 0, r = 0;
    while (s1[l1] != '\0') {
        l1++;
    }
    while (s2[l2] != '\0') {
        l2++;
    }
    char *result = malloc((l1 + l2 + 1) * sizeof(char));
    l1 = 0;
    l2 = 0;
    while (s1[l1] != '\0') {
        result[r++] = s1[l1++];
    }
    while (s2[l2] != '\0') {
        result[r++] = s2[l2++];
    }
    result[r] = '\0';
    return result;
}
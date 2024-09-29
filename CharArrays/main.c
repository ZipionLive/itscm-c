#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getStringLength(char *str);

int main(void)
{
    char *str = "TEST\n";
    printf("%s\n", str);

    char *alphabet = malloc(27 * sizeof(char));
    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'A' + i;
    }
    alphabet[26] = '\0';
    printf("%s\n", alphabet);
    printf("%d\n", getStringLength(alphabet));
    printf("%lu\n", strlen(alphabet));
    free(alphabet);
    return 0;
}

int getStringLength(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}
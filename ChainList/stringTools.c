//
// Created by zipionlive on 9/11/24.
//

#include "stringTools.h"

#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getLength(const char *str) {
    int idx = 0;
    while (str[idx] != '\0' && str[idx] != '\n') {
        idx++;
    }
    return idx;
}

int countStringParts(const char *str, const char delimiter) {
    int idx = 0;
    int result = 0;
    while (str[idx] != '\0') {
        if (str[idx++] == delimiter) {
            result++;
        }
    }
    return result + 1;
}

char **splitString(const char *str, const char delimiter, int *sizeOutput) {
    *sizeOutput = countStringParts(str, delimiter);
    char *strCopy = strdup(str); // copying str because strtok modifies its target
    char **result = malloc(*sizeOutput * sizeof(char *));

    int idx = 0;
    char *buffer = strtok(strCopy, &delimiter);
    while (buffer != NULL) {
        result[idx++] = strdup(buffer);
        buffer = strtok(NULL, &delimiter);
    }

    free(strCopy);
    return result;
}

int stringToInt(const char *str) {
    char *endChar;
    int result = -1;

    // Reset errno to 0 before using strtol
    errno = 0;

    // converting into a long typed buffer
    const long buffer = strtol(str, &endChar, 10); // conversion in base 10

    if (errno == ERANGE) {
        printf("Numeric conversion impossible for string \"%s\" : output outside of long range.\n", str);
    } else if (buffer > INT_MAX || buffer < INT_MIN) {
        printf("Numeric conversion impossible for string \"%s\" : output outside of int range.\n", str);
    } else if (*endChar != '\0' && *endChar != '\n') {
        printf("conversion stopped at \"%s\" : input is not fully numeric\n", endChar);
    } else if (endChar == str) {
        printf("conversion stopped at \"%s\" : input is empty\n", endChar);
    } else {
        result = (int)buffer;
    }

    return result;
}

int isEqualString(const char *str1, const char *str2) {
    const int l1 = getLength(str1);
    const int l2 = getLength(str2);

    // length mismatch
    if (l1 != l2) {
        return 0;
    }

    for (int i = 0; i < l1; i++) {
        // character mismatch
        if (str1[i] != str2[i]) {
            return 0;
        }
    }

    return 1;
}
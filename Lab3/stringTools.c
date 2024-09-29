//
// Created by zipionlive on 29/09/24.
//

#include "stringTools.h"

#include <stdio.h>
#include <stdlib.h>

char getUserChar() {
    char c;
    do {
        c = getchar();
    } while (c == '\n');
    return c;
}

char *getUserString(const int maxSize) {
    char *str = malloc(maxSize * sizeof(char));
    scanf(" %[^\n]", str);
    const int length = getLengthToCarriageReturn(str);
    str[length] = '\0';

    realloc(str, (length + 1) * sizeof(char));

    return str;
}

int getLength(const char *str) {
    int count = 0;
    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int getLengthToCarriageReturn(const char *str) {
    if (str == NULL) {
        return 0;
    }

    int count = 0;
    while (str[count] != '\0' && str[count] != '\n') {
        count++;
    }
    return count;
}

int getAsciiCode() {
    printf("Type a character : ");
    fflush(stdout);
    getchar();
    const char c = getchar();
    printf("\n");
    return c;
}

char *reverse(const char *str) {
    const int length = getLength(str);

    if (length > 20) {
        printf("String is too long (max : 20 characters)\n");
        return NULL;
    }

    char *reversed = malloc(length + 1 * sizeof(char));

    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - 1 - i];
    }
    reversed[length] = '\0';

    return reversed;
}

bool isPalindrome(const char *str) {
    const int length = getLength(str);

    if (length > 30) {
        printf("String is too long (max : 30 characters)\n");
        return false;
    }

    char *reversed = reverse(str);
    bool isPalindrome = true;

    for (int i = 0; i < length; i++) {
        if (str[i] != reversed[i]) {
            isPalindrome = false;
            break;
        }
    }

    free(reversed);
    return isPalindrome;
}

int getVowelCount(const char *str) {
    const int length = getLength(str);

    if (length > 20) {
        printf("String is too long (max : 20 characters)\n");
        return -1;
    }

    int count = 0;

    for (int i = 0; i < length; i++) {
        const char vowels[] = "AEYUIOaeyuio";
        int idx = 0;
        while (vowels[idx] != '\0') {
            count += str[i] == vowels[idx] ? 1 : 0;
            idx++;
        }
    }

    return count;
}

int compareAndGetLength(const char *str1, const char *str2) {
    const int length1 = getLength(str1);
    const int length2 = getLength(str2);

    if (length1 != length2) {
        return -1;
    }


    for (int i = 0; i < length1; i++) {
        if (str1[i] != str2[i]) {
            return -1;
        }
    }

    return length1;
}

bool contains2to5(const char *source, const char *compared) {
    const int lengthSource = getLength(source);
    if (lengthSource < 6) {
        printf("String is too short (min : 6 characters)\n");
    }

    const int lengthCompared = getLength(compared);
    char *twoToFive = substring(source, 2, 6);

    bool contains = false;

    for (int i = 0; i < lengthCompared - 4; i++) {
        if (compared[i] == twoToFive[0]
            && compared[i + 1] == twoToFive[1]
            && compared[i + 2] == twoToFive[2]
            && compared[i + 3] == twoToFive[3]) {
            contains = true;
            break;
        }
    }

    free(twoToFive);
    return contains;
}

char *substring(const char *str, const int startIndex, const int endIndex) {
    const int length = getLength(str);

    if (length < endIndex) {
        printf("String is too short for substring parameters (min : %d characters)\n", endIndex);
    }

    char *substring = malloc((endIndex - startIndex) * sizeof(char));

    for (int i = 0; i < endIndex - startIndex; i++) {
        substring[i] = str[startIndex + i];
    }

    return substring;
}

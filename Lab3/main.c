#include <stdio.h>
#include <stdlib.h>

#include "stringTools.h"

void run();

int main(void)
{
    run();
    return 0;
}

void run() {
    printf("\n\n");
    printf("[1] : Get ASCII code\n");
    printf("[2] : Reverse string\n");
    printf("[3] : Check for palindrome\n");
    printf("[4] : Count vowels\n");
    printf("[5] : Compare strings and return length\n");
    printf("[6] : Check for 2to5 pattern\n");
    printf("[0] : STOP\n");
    printf("Enter a number to choose a function : ");
    char c = getUserChar();
    putchar(c);
    printf("\n");
    switch (c) {
        case '0':
            return;
        case '1':
            const int code = getAsciiCode();
            printf("The ASCII code is %d\n", code);
            break;
        case '2':
            printf("Write something :\n");
            char *str2 = getUserString(100);
            printf("The user string is \"%s\"\n", str2);
            char *reversed = reverse(str2);
            printf("The reversed string is \"%s\"\n", reversed);
            free(str2);
            free(reversed);
            break;
        case '3':
            printf("Write something :\n");
            char *str3 = getUserString(100);
            printf("The user string is \"%s\"\n", str3);
            printf(isPalindrome(str3)
                ? "The string is a palindrome !\n"
                : "The string is not a palindrome !\n");
            free(str3);
            break;
        case '4':
            printf("Write something :\n");
            char *str4 = getUserString(100);
            printf("The user string is \"%s\"\n", str4);
            const int vowels = getVowelCount(str4);
            printf("The number of vowels is %d\n", vowels);
            free(str4);
            break;
        case '5':
            printf("Write something :\n");
            char *str5a = getUserString(100);
            printf("The first user string is \"%s\"\n", str5a);
            printf("Write something else :\n");
            char *str5b = getUserString(100);
            printf("The second user string is \"%s\"\n", str5b);
            int lengthIfEqual = compareAndGetLength(str5a, str5b);
            if (lengthIfEqual == -1) {
                printf("The strings aren't identical !\n");
            } else {
                printf("The strings are identical and are %d characters long !\n", lengthIfEqual);
            }
            free(str5a);
            free(str5b);
            break;
        case '6':
            printf("Write something :\n");
            char *str6a = getUserString(100);
            printf("The first user string is \"%s\"\n", str6a);
            printf("Write something else :\n");
            char *str6b = getUserString(100);
            printf("The second user string is \"%s\"\n", str6b);
            if (contains2to5(str6a, str6b) == true) {
                printf("The second string contains the sequence between index 2 and 5 from the first string !\n");
            } else {
                printf("The second string doesn't contain the sequence between index 2 and 5 from the first string.\n");
            }
            free(str6a);
            free(str6b);
            break;
        default:
            break;
    }

    run();
}
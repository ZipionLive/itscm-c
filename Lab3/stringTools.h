//
// Created by zipionlive on 29/09/24.
//

#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H
#include <stdbool.h>

char getUserChar();
char *getUserString(int maxSize);
int getLength(const char *str);
int getLengthToCarriageReturn(const char *str);
int getAsciiCode();
char *reverse(const char *str);
bool isPalindrome(const char *str);
int getVowelCount(const char *str);
int compareAndGetLength(const char *str1, const char *str2);
bool contains2to5(const char *source, const char *compared);
char *substring(const char *str, int startIndex, int endIndex);

#endif //STRINGTOOLS_H

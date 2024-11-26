//
// Created by zipionlive on 9/11/24.
//

#ifndef STRINGTOOLS_H
#define STRINGTOOLS_H

int getLength(const char *str);
int countStringParts(const char *str, char delimiter);
char **splitString(const char *str, char delimiter, int *sizeOutput);
int stringToInt(const char *str);
float stringToFloat(const char *str);
int isEqualString(const char *str1, const char *str2);
char *padNumber(int value, int length);

#endif //STRINGTOOLS_H

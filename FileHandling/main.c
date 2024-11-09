#include <stdio.h>
#include <stdlib.h>

#include "fileHandling.h"

int main(void)
{
    char *bashFile = "/home/zipionlive/.bashrc";
    char *testFile1 = "/home/zipionlive/Documents/testFile1.txt";
    char *testFile2 = "/home/zipionlive/Documents/testFile2.txt";
    char *copyFile1 = "/home/zipionlive/Documents/copyFile1.txt";
    char *copyFile2 = "/home/zipionlive/Documents/copyFile2.txt";
    char *testFileContent = "Hello World!\nThis is my file content!";
    int result = readFileByChar(bashFile);
    result += readFileByLine(bashFile);
    result += writeFileByChar(testFileContent, testFile1);
    result += readFileByChar(testFile1);
    char **content = malloc(3 * sizeof(char *));
    content[0] = "This is the 1st line\n";
    content[1] = "This is the 2nd line\n";
    content[2] = "This is the 3rd line";
    result += writeFileByLine(content, 3, testFile2);
    free(content);
    result += readFileByLine(testFile2);
    result += copyFileByChar(testFile1, copyFile1);
    result += readFileByChar(copyFile1);
    result += copyFileByLine(testFile2, copyFile2);
    result += readFileByLine(copyFile2);
    char **toDelete = malloc(4 * sizeof(char *));
    toDelete[0] = testFile1;
    toDelete[1] = testFile2;
    toDelete[2] = copyFile1;
    toDelete[3] = copyFile2;
    result += deleteFiles(toDelete, 4);
    free(toDelete);
    return result;
}

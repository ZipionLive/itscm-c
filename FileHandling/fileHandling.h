//
// Created by zipionlive on 9/11/24.
//

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

int readFileByChar(char *filePath);
int readFileByLine(char *filePath);
int writeFileByChar(char *content, char *filePath);
int writeFileByLine(char **content, int lines, char *filePath);
int copyFileByChar(char *sourcePath, char *destinationPath);
int copyFileByLine(char *sourcePath, char *destinationPath);
int deleteFile(char *filePath);
int deleteFiles(char **filePaths, int files);

#endif //FILEHANDLING_H

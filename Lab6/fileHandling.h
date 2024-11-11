//
// Created by zipionlive on 9/11/24.
//

#ifndef FILEHANDLING_H
#define FILEHANDLING_H

char **readFileByLine(char *filePath, int lines);
int writeFileByLine(char **content, int lines, char *filePath);
int deleteFile(char *filePath);

#endif //FILEHANDLING_H

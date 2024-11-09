//
// Created by zipionlive on 9/11/24.
//

#include "fileHandling.h"

#include <stdio.h>

#define FILE_ERROR 1
#define READ_ERROR 2
#define WRITE_ERROR 3
#define DELETE_ERROR 4

int readFileByChar(char *filePath) {
    FILE *file = fopen(filePath, "r");

    if (file != NULL) {
        printf(">>> File \"%s\" opened successfully !\n\n", filePath);

        int c;
        while ((c = getc(file)) != EOF) {
            printf("%c", c);
        }

        if (feof(file)) {
            printf("\n\n>>> File \"%s\" parsed successfully !\n\n", filePath);
        } else if (ferror(file)) {
            printf("\n\n>>> File \"%s\" read error !\n\n", filePath);
            return READ_ERROR;
        }

        return fclose(file);
    }

    printf(">>> File not found...\n");
    return FILE_ERROR;
}

int readFileByLine(char *filePath) {
    FILE *file = fopen(filePath, "r");

    if (file != NULL) {
        printf(">>> File \"%s\" opened successfully !\n\n", filePath);

        char buffer[512];
        while (fgets(buffer, 512, file) != NULL) {
            printf("%s", buffer);
        }

        if (feof(file)) {
            printf("\n\n>>> File \"%s\" parsed successfully !\n\n", filePath);
        } else if (ferror(file)) {
            printf("\n\n>>> File \"%s\" read error !\n\n", filePath);
            return READ_ERROR;
        }

        return fclose(file);
    }

    printf(">>> File not found...\n");
    return FILE_ERROR;
}

int writeFileByChar (char *content, char *filePath) {
    FILE *file = fopen(filePath, "w");

    if (file != NULL) {
        printf(">>> File \"%s\" created successfully !\n\n", filePath);

        int charIdx = 0;
        while (content[charIdx] != '\0') {
            if (fputc(content[charIdx], file) == EOF) {
                printf("\n\n>>> Error while writing file \"%s\".\n\n", filePath);
                return WRITE_ERROR;
            };
            charIdx++;
        }

        printf(">>> File \"%s\" written successfully !\n\n", filePath);
        return fclose(file);
    }

    printf(">>> File creation failed...");
    return FILE_ERROR;
}

int writeFileByLine(char **content, const int lines, char *filePath) {
    FILE *file = fopen(filePath, "w");

    if (file != NULL) {
        printf(">>> File \"%s\" created successfully !\n\n", filePath);

        for (int i = 0; i < lines; i++) {
            if (fputs(content[i], file) == EOF) {
                printf("\n\n>>> Error while writing file \"%s\".\n\n", filePath);
                return WRITE_ERROR;
            }
        }

        printf(">>> File \"%s\" written successfully !\n\n", filePath);
        return fclose(file);
    }

    printf(">>> File creation failed...");
    return FILE_ERROR;
}

int copyFileByChar(char *sourcePath, char *destinationPath) {
    FILE *source = fopen(sourcePath, "r");
    FILE *destination = fopen(destinationPath, "w");

    if (source == NULL) {
        printf(">>> Error while opening file \"%s\".\n\n", sourcePath);
        return FILE_ERROR;
    }

    if (destination == NULL) {
        printf(">>> Error while creating file \"%s\".\n\n", destinationPath);
        return FILE_ERROR;
    }

    int c;
    while ((c = getc(source)) != EOF) {
        fputc(c, destination);
    }

    if (feof(source)) {
        printf("\n\n>>> File \"%s\" parsed successfully !\n\n", sourcePath);
    } else if (ferror(source) != 0) {
        printf("\n\n>>> File \"%s\" read error !\n\n", sourcePath);
        return READ_ERROR;
    }

    printf(">>> File \"%s\" copied to \"%s\" successfully !\n\n", sourcePath, destinationPath);
    return fclose(source) + fclose(destination);
}

int copyFileByLine(char *sourcePath, char *destinationPath) {
    FILE *source = fopen(sourcePath, "r");
    FILE *destination = fopen(destinationPath, "w");

    if (source == NULL) {
        printf(">>> Error while opening file \"%s\".\n\n", sourcePath);
        return FILE_ERROR;
    }

    if (destination == NULL) {
        printf(">>> Error while creating file \"%s\".\n\n", destinationPath);
        return WRITE_ERROR;
    }

    char buffer[512];
    while (fgets(buffer, 512, source) != NULL) {
        fputs(buffer, destination);
    }

    if (feof(source)) {
        printf("\n\n>>> File \"%s\" parsed successfully !\n\n", sourcePath);
    } else if (ferror(source) != 0) {
        printf("\n\n>>> File \"%s\" read error !\n\n", sourcePath);
        return READ_ERROR;
    }

    printf(">>> File \"%s\" copied to \"%s\" successfully !\n\n", sourcePath, destinationPath);
    return fclose(source) + fclose(destination);
}

int deleteFile(char *filePath) {
    if (remove(filePath) == 0) {
        printf(">>> File \"%s\" deleted successfully !\n\n", filePath);
        return 0;
    }

    printf(">>> File \"%s\" could not be deleted !\n\n", filePath);
    return DELETE_ERROR;
}

int deleteFiles(char **filePaths, const int files) {
    int result = 0;

    for (int i = 0; i < files; i++) {
        const int deleteResult = deleteFile(filePaths[i]);
        result = deleteResult >= result ? deleteResult : result;
    }

    printf(">>> All files deleted successfully !\n\n");
    return result;
}
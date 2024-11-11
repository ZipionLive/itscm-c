//
// Created by zipionlive on 9/11/24.
//

#include "fileHandling.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_ERROR 1
#define READ_ERROR 2
#define WRITE_ERROR 3
#define DELETE_ERROR 4
#define BUFFER_SIZE 512

char **readFileByLine(char *filePath, const int lines) {
    FILE *file = fopen(filePath, "r");
    char **result = malloc(lines * sizeof(char *));

    if (file != NULL) {
        printf("\n>>> File \"%s\" opened successfully !\n", filePath);

        char buffer[BUFFER_SIZE];
        int i = 0;
        while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
            if (i < lines) {
                result[i++] = strdup(buffer);
            }
        }

        if (feof(file)) {
            printf("\n>>> File \"%s\" parsed successfully !\n", filePath);
        } else if (ferror(file)) {
            printf("\n>>> File \"%s\" read error !\n", filePath);
            return NULL;
        }

        if (fclose(file) == 0) {
            printf("\n>>> File \"%s\" closed successfully !\n", filePath);
            return result;
        }

        return NULL;
    }

    printf("\n>>> File not found...\n");
    return NULL;
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

int deleteFile(char *filePath) {
    if (remove(filePath) == 0) {
        printf(">>> File \"%s\" deleted successfully !\n\n", filePath);
        return 0;
    }

    printf(">>> File \"%s\" could not be deleted !\n\n", filePath);
    return DELETE_ERROR;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
} File;

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    File files[MAX_FILES];
    int fileCount;
} Directory;

int createFile(Directory* dir, const char* filename) {
    if (dir->fileCount >= MAX_FILES) {
        printf("Directory is full. Cannot create more files.\n");
        return -1;
    }

    // Check if file already exists
    for (int i = 0; i < dir->fileCount; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            printf("File '%s' already exists.\n", filename);
            return -1;
        }
    }

    // Create new file
    File newFile;
    strcpy(newFile.name, filename);
    dir->files[dir->fileCount++] = newFile;

    printf("File '%s' created successfully.\n", filename);
    return 0;
}

void displayFiles(Directory* dir) {
    if (dir->fileCount == 0) {
        printf("Directory is empty.\n");
        return;
    }

    printf("Files in directory '%s':\n", dir->name);
    for (int i = 0; i < dir->fileCount; i++) {
        printf("%s\n", dir->files[i].name);
    }
}

int main() {
    Directory cseDirectory;
    strcpy(cseDirectory.name, "CSE");
    cseDirectory.fileCount = 0;

    createFile(&cseDirectory, "A");
    createFile(&cseDirectory, "B");
    createFile(&cseDirectory, "C");

    displayFiles(&cseDirectory);

    return 0;
}


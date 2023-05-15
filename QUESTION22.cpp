#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_FILES 3

struct Directory {
    char name[20];
    char files[MAX_FILES][20];
    int fileCount;
};

struct User {
    char name[20];
    struct Directory directory;
};

void createUserDirectory(struct User *user, char *directoryName) {
    strcpy(user->directory.name, directoryName);
    user->directory.fileCount = 0;
}

void createFile(struct User *user, char *fileName) {
    if (user->directory.fileCount == MAX_FILES) {
        printf("Maximum file limit reached for user %s.\n", user->name);
        return;
    }
    
    strcpy(user->directory.files[user->directory.fileCount], fileName);
    user->directory.fileCount++;
}

int main() {
    struct User users[MAX_USERS];
    char directoryName[20];
    char fileName[20];

    // Create user directories
    for (int i = 0; i < MAX_USERS; i++) {
        sprintf(users[i].name, "user%d", i + 1);
        createUserDirectory(&users[i], users[i].name);
    }

    // Create files in user directories
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_FILES; j++) {
            sprintf(fileName, "file%d_%d.txt", i + 1, j + 1);
            createFile(&users[i], fileName);
        }
    }

    // Print user directories and files
    for (int i = 0; i < MAX_USERS; i++) {
        printf("User: %s\n", users[i].name);
        printf("Directory: %s\n", users[i].directory.name);
        printf("Files: ");
        for (int j = 0; j < users[i].directory.fileCount; j++) {
            printf("%s ", users[i].directory.files[j]);
        }
        printf("\n\n");
    }

    return 0;
}


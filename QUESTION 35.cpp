#include <stdio.h>

#define DISK_SIZE 16
#define BLOCK_SIZE 1024
#define INODE_BLOCKS 8
#define DATA_BLOCKS (DISK_SIZE - INODE_BLOCKS)

int disk[DISK_SIZE];
int nextFreeBlock = INODE_BLOCKS; // Start from the first available data block

// Function to allocate blocks for a file
void allocateBlocks(int startBlock, int numBlocks) {
    // Check if the requested blocks are free
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        if (disk[i] != 0) {
            printf("Error: Blocks %d to %d are not free\n", startBlock, startBlock + numBlocks - 1);
            return;
        }
    }

    // Allocate the blocks
    for (int i = startBlock; i < startBlock + numBlocks; i++) {
        disk[i] = 1;
    }

    printf("Allocated blocks %d to %d for the file\n", startBlock, startBlock + numBlocks - 1);
}

// Function to find the next available contiguous blocks
int findNextContiguousBlocks(int numBlocks) {
    int startBlock = -1;
    int contiguousCount = 0;

    for (int i = nextFreeBlock; i < DISK_SIZE; i++) {
        if (disk[i] == 0) {
            if (startBlock == -1) {
                startBlock = i;
            }

            contiguousCount++;

            if (contiguousCount == numBlocks) {
                nextFreeBlock = i + 1;
                return startBlock;
            }
        } else {
            startBlock = -1;
            contiguousCount = 0;
        }
    }

    return -1; // No contiguous blocks available
}

int main() {
    int fileSize;
    int startBlock;
    int numBlocks;

    printf("Enter file size in KB: ");
    scanf("%d", &fileSize);

    // Check if file size is valid
    if (fileSize < 1) {
        printf("Error: Invalid file size\n");
        return 0;
    }

    // Calculate the number of blocks required
    numBlocks = fileSize / BLOCK_SIZE;
    if (fileSize % BLOCK_SIZE != 0) {
        numBlocks++;
    }

    // Check if there are enough contiguous blocks available
    startBlock = findNextContiguousBlocks(numBlocks);
    if (startBlock == -1) {
        printf("Error: Not enough contiguous blocks available for the file\n");
        return 0;
    }

    // Allocate the blocks for the file
    allocateBlocks(startBlock, numBlocks);

    return 0;
}


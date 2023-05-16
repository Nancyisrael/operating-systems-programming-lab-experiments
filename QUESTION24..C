#include <stdio.h>

#define BLOCK_SIZE 8192 // 8 KB
#define POINTER_SIZE 4 // 4 bytes
#define DIRECT_BLOCKS 12
#define INDIRECT_BLOCKS (BLOCK_SIZE / POINTER_SIZE)
#define DOUBLE_INDIRECT_BLOCKS (INDIRECT_BLOCKS * INDIRECT_BLOCKS)
#define TRIPLE_INDIRECT_BLOCKS (INDIRECT_BLOCKS * DOUBLE_INDIRECT_BLOCKS)

long long calculateMaxFileSize()
{
    long long maxFileSize = 0;
    
    // Calculate the maximum size of file that can be stored using direct blocks
    maxFileSize += DIRECT_BLOCKS * BLOCK_SIZE;
    
    // Calculate the maximum size of file that can be stored using single indirect blocks
    maxFileSize += INDIRECT_BLOCKS * BLOCK_SIZE;
    
    // Calculate the maximum size of file that can be stored using double indirect blocks
    maxFileSize += DOUBLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    
    // Calculate the maximum size of file that can be stored using triple indirect blocks
    maxFileSize += TRIPLE_INDIRECT_BLOCKS * BLOCK_SIZE;
    
    return maxFileSize;
}

int main()
{
    long long maxFileSize = calculateMaxFileSize();
    printf("Maximum size of a file that can be stored: %lld bytes\n", maxFileSize);
    
    return 0;
}


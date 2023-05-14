#include <stdio.h>

int main() {
    int pageFrames = 3;  // Number of page frames
    int pageReferences[] = {4, 1, 2, 4, 3, 2, 1, 5};  // Page reference sequence
    int referenceLength = sizeof(pageReferences) / sizeof(pageReferences[0]);

    int pageTable[pageFrames];  // Page table to store the page frames
    int pageFaults = 0;  // Counter for page faults

    // Initialize page table with -1 indicating an empty frame
    for (int i = 0; i < pageFrames; i++) {
        pageTable[i] = -1;
    }

    // Iterate over the page reference sequence
    for (int i = 0; i < referenceLength; i++) {
        int currentPage = pageReferences[i];
        int pageHit = 0;  // Flag to indicate if page is already present in page table

        // Check if the current page is already present in the page table
        for (int j = 0; j < pageFrames; j++) {
            if (pageTable[j] == currentPage) {
                pageHit = 1;
                break;
            }
        }

        // If the page is not present in the page table, replace the oldest page (FIFO)
        if (pageHit == 0) {
            pageTable[pageFaults % pageFrames] = currentPage;
            pageFaults++;
        }

        // Print the current page table
        printf("Page Table: ");
        for (int j = 0; j < pageFrames; j++) {
            printf("%d ", pageTable[j]);
        }
        printf("\n");
    }

    printf("Number of Page Faults: %d\n", pageFaults);

    return 0;
}


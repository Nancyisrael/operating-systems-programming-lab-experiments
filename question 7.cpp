#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int pageFrames[MAX_FRAMES];
    int pageFaults = 0;
    int pageReference[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int numPages = sizeof(pageReference) / sizeof(pageReference[0]);
    int numFrames = 0;
    int i, j, k;

    // Initialize page frames to -1 (indicating an empty frame)
    for (i = 0; i < MAX_FRAMES; i++) {
        pageFrames[i] = -1;
    }

    // Iterate over the page reference sequence
    for (i = 0; i < numPages; i++) {
        int currentPage = pageReference[i];
        int pageFound = 0;

        // Check if the current page is already in a page frame
        for (j = 0; j < numFrames; j++) {
            if (pageFrames[j] == currentPage) {
                pageFound = 1;
                break;
            }
        }

        // If page not found in the page frames, it's a page fault
        if (pageFound == 0) {
            // If all the frames are filled, find the least recently used page
            if (numFrames == MAX_FRAMES) {
                int minIndex = i;
                int replacePage = -1;
                for (j = 0; j < numFrames; j++) {
                    int framePage = pageFrames[j];
                    for (k = i - 1; k >= 0; k--) {
                        if (framePage == pageReference[k]) {
                            if (k < minIndex) {
                                minIndex = k;
                                replacePage = j;
                            }
                            break;
                        }
                    }
                }

                // Replace the least recently used page with the current page
                pageFrames[replacePage] = currentPage;
                pageFaults++;
            }
            // If there are empty frames, use one of them
            else {
                pageFrames[numFrames] = currentPage;
                numFrames++;
                pageFaults++;
            }
        }

        // Print the current state of page frames
        printf("Page Frames: ");
        for (j = 0; j < numFrames; j++) {
            printf("%d ", pageFrames[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}

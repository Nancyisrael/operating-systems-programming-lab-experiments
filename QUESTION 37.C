#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 3
#define MAX_PAGES 8

int main() {
    int pageFrames[MAX_FRAMES] = {0};
    int pageReferences[MAX_PAGES] = {4, 1, 2, 4, 3, 2, 1, 5};
    int pageFaults = 0;
    bool pagePresent;

    for (int i = 0; i < MAX_PAGES; i++) {
        int currentPage = pageReferences[i];
        pagePresent = false;

        // Check if the page is already present in a frame
        for (int j = 0; j < MAX_FRAMES; j++) {
            if (pageFrames[j] == currentPage) {
                pagePresent = true;
                break;
            }
        }

        // If the page is not present, replace the optimal page
        if (!pagePresent) {
            int replaceIndex = -1;
            int farthestDistance = -1;

            // Find the page in the frames that will be referenced farthest in the future
            for (int j = 0; j < MAX_FRAMES; j++) {
                bool found = false;
                for (int k = i + 1; k < MAX_PAGES; k++) {
                    if (pageFrames[j] == pageReferences[k]) {
                        found = true;
                        if (k > farthestDistance) {
                            farthestDistance = k;
                            replaceIndex = j;
                        }
                        break;
                    }
                }
                if (!found) {
                    replaceIndex = j;
                    break;
                }
            }

            // Replace the page at the replaceIndex with the current page
            pageFrames[replaceIndex] = currentPage;
            pageFaults++;
        }
    }

    printf("Number of page faults: %d\n", pageFaults);

    return 0;
}


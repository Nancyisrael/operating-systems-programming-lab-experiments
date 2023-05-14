#include <stdio.h>

// Function to check if a page exists in the given frame
int isPageExists(int page, int frame[], int num_frames) {
    for (int i = 0; i < num_frames; i++) {
        if (frame[i] == page) {
            return 1; // Page found in frame
        }
    }
    return 0; // Page not found in frame
}

// Function to find the page to be replaced
int findReplacementPage(int pages[], int num_pages, int frame[], int num_frames, int current_index) {
    int longest_future = -1; // Index of page that is not demanded for the longest future time
    int replacement_page = -1; // Page to be replaced
    
    for (int i = 0; i < num_frames; i++) {
        int found = 0; // Flag to check if page is demanded in future
        
        for (int j = current_index + 1; j < num_pages; j++) {
            if (frame[i] == pages[j]) {
                found = 1;
                if (j > longest_future) {
                    longest_future = j;
                    replacement_page = i;
                }
                break;
            }
        }
        
        if (!found) {
            return i; // Page not demanded in future, can be replaced
        }
    }
    
    return replacement_page;
}

// Function to simulate the page replacement algorithm
int simulatePageReplacement(int pages[], int num_pages, int num_frames) {
    int frame[num_frames]; // Array to hold the page frames
    int page_faults = 0; // Counter for page faults
    
    for (int i = 0; i < num_frames; i++) {
        frame[i] = -1; // Initialize frames to -1 (empty)
    }
    
    for (int i = 0; i < num_pages; i++) {
        if (!isPageExists(pages[i], frame, num_frames)) {
            int replacement_index = findReplacementPage(pages, num_pages, frame, num_frames, i);
            frame[replacement_index] = pages[i];
            page_faults++;
        }
    }
    
    return page_faults;
}

int main() {
    int num_frames = 3;
    int num_pages = 19;
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
    
    int page_faults = simulatePageReplacement(pages, num_pages, num_frames);
    
    printf("Number of page faults: %d\n", page_faults);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Function to sort an array in ascending order
void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to find the index of track position in the sorted array
int findIndex(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // Track position not found
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int headPos = 50; // Initial head position
    int direction = 1; // 1 for right, -1 for left
    int totalHeadMovement = 0;
    int i, currentIndex;

    sort(tracks, numTracks); // Sort the track positions in ascending order

    // Find the index of head position in the sorted array
    currentIndex = findIndex(tracks, numTracks, headPos);

    // Scan right until the end and then change direction
    for (i = currentIndex; i < numTracks; i++) {
        totalHeadMovement += abs(headPos - tracks[i]);
        headPos = tracks[i];
    }

    // Scan left from the current head position until the beginning
    for (i = currentIndex - 1; i >= 0; i--) {
        totalHeadMovement += abs(headPos - tracks[i]);
        headPos = tracks[i];
    }

    printf("Average head movement: %.2f\n", (float)totalHeadMovement / numTracks);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Function to sort the tracks in ascending order
void sortTracks(int *tracks, int numTracks) {
    int i, j;
    for (i = 0; i < numTracks - 1; i++) {
        for (j = i + 1; j < numTracks; j++) {
            if (tracks[i] > tracks[j]) {
                int temp = tracks[i];
                tracks[i] = tracks[j];
                tracks[j] = temp;
            }
        }
    }
}

// Function to simulate the SCAN disk scheduling algorithm
int scan(int *tracks, int numTracks, int headPosition) {
    int totalMovement = 0;
    int i, currentIndex, direction;
    int headIndex = -1;

    // Find the initial head index
    for (i = 0; i < numTracks; i++) {
        if (tracks[i] == headPosition) {
            headIndex = i;
            break;
        }
    }

    if (headIndex == -1) {
        printf("Invalid head position.\n");
        return -1;
    }

    // Sort the tracks in ascending order
    sortTracks(tracks, numTracks);

    // Determine the direction of head movement
    if (headIndex < numTracks / 2)
        direction = 1;  // Move towards higher tracks
    else
        direction = -1; // Move towards lower tracks

    currentIndex = headIndex;
    printf("Head Movement: %d", headPosition);

    // Scan towards higher tracks
    while (currentIndex < numTracks && currentIndex >= 0) {
        printf(" -> %d", tracks[currentIndex]);
        totalMovement += abs(headPosition - tracks[currentIndex]);
        headPosition = tracks[currentIndex];
        currentIndex += direction;
    }

    // Scan towards lower tracks
    direction = -direction;
    currentIndex = headIndex - direction;
    while (currentIndex >= 0 && currentIndex < numTracks) {
        printf(" -> %d", tracks[currentIndex]);
        totalMovement += abs(headPosition - tracks[currentIndex]);
        headPosition = tracks[currentIndex];
        currentIndex -= direction;
    }

    printf("\n");
    return totalMovement;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int numTracks = sizeof(tracks) / sizeof(tracks[0]);
    int headPosition = 55;
    int avgHeadMovement;

    avgHeadMovement = scan(tracks, numTracks, headPosition);

    if (avgHeadMovement != -1) {
        printf("Average Head Movement: %.2f\n", (float)avgHeadMovement / numTracks);
    }

    return 0;
}


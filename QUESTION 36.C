#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int currentTrack = 50;  // Starting position of the disk head
    int totalHeadMovement = 0;

    for (int i = 0; i < n; i++) {
        int minDistance = abs(currentTrack - tracks[i]);
        int minIndex = i;

        // Find the track with minimum distance from the current track
        for (int j = i + 1; j < n; j++) {
            int distance = abs(currentTrack - tracks[j]);
            if (distance < minDistance) {
                minDistance = distance;
                minIndex = j;
            }
        }

        // Swap the current track with the track having minimum distance
        int temp = tracks[i];
        tracks[i] = tracks[minIndex];
        tracks[minIndex] = temp;

        // Update the current track and calculate the head movement
        totalHeadMovement += minDistance;
        currentTrack = tracks[i];
    }

    // Print the sorted track order and average head movement
    printf("Sorted track order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\nAverage head movement: %.2f\n", (float)totalHeadMovement / n);

    return 0;
}


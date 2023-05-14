#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 9; // Number of tracks
    int tracks[] = {55, 58, 60, 70, 18, 90, 150, 160, 184}; // Track positions
    int head = 50; // Initial head position
    int total_movement = 0; // Total head movement

    printf("Track Positions: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tracks[i]);
    }
    printf("\n");

    printf("Head Movement: %d", abs(tracks[0] - head));
    total_movement += abs(tracks[0] - head);

    for (int i = 1; i < n; i++) {
        printf(" -> %d", abs(tracks[i] - tracks[i - 1]));
        total_movement += abs(tracks[i] - tracks[i - 1]);
    }

    printf("\nAverage Head Movement: %.2f\n", (float)total_movement / n);

    return 0;
}


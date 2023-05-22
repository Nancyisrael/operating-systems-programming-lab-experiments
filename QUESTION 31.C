#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

void cscan(int tracks[], int n, int start) {
    int total_head_movement = 0;
    int current_track = start;
    int direction = 1; // 1 for moving towards higher track numbers, -1 for lower track numbers

    // Sort the tracks in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Find the position to change direction
    int position;
    for (position = 0; position < n; position++) {
        if (tracks[position] > start) {
            break;
        }
    }

    // Move towards higher track numbers
    for (int i = position; i < n; i++) {
        total_head_movement += abs_diff(current_track, tracks[i]);
        current_track = tracks[i];
    }

    // Move towards lower track numbers
    total_head_movement += abs_diff(current_track, tracks[n - 1]);
    current_track = tracks[n - 1];
    total_head_movement += abs_diff(current_track, 0);
    current_track = 0;

    // Move towards higher track numbers again
    for (int i = 0; i < position; i++) {
        total_head_movement += abs_diff(current_track, tracks[i]);
        current_track = tracks[i];
    }

    printf("Average head movement: %.2f\n", (float)total_head_movement / n);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int start_track = 50;

    cscan(tracks, num_tracks, start_track);

    return 0;
}


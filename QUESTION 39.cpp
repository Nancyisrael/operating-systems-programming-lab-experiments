#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int current_track, direction, total_head_movement = 0;
    int i, j, next_track;

    // Sort the tracks in ascending order
    for (i = 0; i < num_tracks - 1; i++) {
        for (j = 0; j < num_tracks - i - 1; j++) {
            if (tracks[j] > tracks[j + 1]) {
                int temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    // Starting position of the disk head
    current_track = 50;

    // Find the initial direction of head movement
    if (current_track > tracks[0])
        direction = -1; // Move towards smaller tracks
    else
        direction = 1; // Move towards larger tracks

    // Iterate over the sorted tracks and calculate head movement
    for (i = 0; i < num_tracks; i++) {
        next_track = tracks[i];

        if (direction == -1 && next_track >= current_track)
            direction = 1; // Change direction if reaching the end

        if (direction == 1 && next_track <= current_track)
            direction = -1; // Change direction if reaching the end

        total_head_movement += abs_diff(current_track, next_track);
        current_track = next_track;
    }

    // Print the average head movement
    float average_head_movement = (float)total_head_movement / num_tracks;
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}


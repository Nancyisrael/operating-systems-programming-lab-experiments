#include <stdio.h>
#include <stdlib.h>

// Function to calculate the absolute difference between two integers
int abs_diff(int a, int b) {
    return abs(a - b);
}

// Function to calculate the average head movement
float calculate_average_head_movement(int tracks[], int n, int initial_position) {
    int head_movement = 0;

    // Calculate the total head movement
    for (int i = 0; i < n; i++) {
        head_movement += abs_diff(initial_position, tracks[i]);
        initial_position = tracks[i];
    }

    // Return the average head movement
    return (float) head_movement / n;
}

int main() {
    int tracks[] = {55, 58, 60, 70, 18};
    int n = sizeof(tracks) / sizeof(tracks[0]);
    int initial_position = 50;  // Assuming initial head position as 50 (can be changed as per requirement)

    // Calculate the average head movement
    float average_head_movement = calculate_average_head_movement(tracks, n, initial_position);

    // Print the results
    printf("Average head movement: %.2f\n", average_head_movement);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

void clook(int tracks[], int n, int start)
{
    int i, j, head, movement = 0;
    int visited[MAX], sequence[MAX], seq_index = 0;

    for (i = 0; i < MAX; i++)
        visited[i] = 0;

    head = start;

    // Find the track closest to the start position
    int closest = 0;
    for (i = 0; i < n; i++) {
        if (abs(tracks[i] - start) < abs(tracks[closest] - start))
            closest = i;
    }

    // Move towards the closest track in the forward direction
    for (i = closest; i < n; i++) {
        if (!visited[i]) {
            sequence[seq_index++] = tracks[i];
            visited[i] = 1;
            movement += abs(head - tracks[i]);
            head = tracks[i];
        }
    }

    // Move towards the starting track in the forward direction
    for (i = 0; i < closest; i++) {
        if (!visited[i]) {
            sequence[seq_index++] = tracks[i];
            visited[i] = 1;
            movement += abs(head - tracks[i]);
            head = tracks[i];
        }
    }

    printf("The sequence of tracks visited:\n");
    for (i = 0; i < seq_index; i++)
        printf("%d ", sequence[i]);

    printf("\nAverage head movement: %.2f\n", (float)movement / n);
}

int main()
{
    int tracks[] = {55, 58, 60, 70, 18};
    int num_tracks = sizeof(tracks) / sizeof(tracks[0]);
    int start_position = 50;

    printf("Number of tracks: %d\n", num_tracks);
    printf("Track positions: ");
    for (int i = 0; i < num_tracks; i++)
        printf("%d ", tracks[i]);
    printf("\n");

    clook(tracks, num_tracks, start_position);

    return 0;
}


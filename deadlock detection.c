#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 3 // Number of resources

int main() {
    int allocation[P][R] = {
        {0, 1, 0}, // P0
        {2, 0, 0}, // P1
        {3, 0, 2}, // P2
        {2, 1, 1}, // P3
        {0, 0, 2}  // P4
    };

    int max[P][R] = {
        {7, 5, 3}, // P0
        {3, 2, 2}, // P1
        {9, 0, 2}, // P2
        {2, 2, 2}, // P3
        {4, 3, 3}  // P4
    };

    int available[R] = {3, 3, 2}; // Available resources

    int need[P][R];
    bool finish[P] = {false};
    int safeSeq[P];
    int work[R];
    int count = 0;

    // Calculate Need matrix
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Initialize work = available
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    // Deadlock detection
    while (count < P) {
        bool found = false;
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < R; j++) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            break; // Deadlock detected
        }
    }

    if (count == P) {
        printf("System is in a SAFE state.\nSafe sequence: ");
        for (int i = 0; i < P; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    } else {
        printf("System is in DEADLOCK state.\n");
        printf("Processes that are deadlocked: ");
        for (int i = 0; i < P; i++) {
            if (!finish[i]) {
                printf("P%d ", i);
            }
        }
        printf("\n");
    }

    return 0;
}

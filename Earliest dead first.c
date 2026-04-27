#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int C;
    int D;
    int arrival;
    int remaining;
    int deadline;
    int completed;
} Process;

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    double U = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Enter execution time (C), deadline (D), arrival time for Process %d: ", i+1);
        scanf("%d %d %d", &p[i].C, &p[i].D, &p[i].arrival);
        p[i].id = i+1;
        p[i].remaining = p[i].C;
        p[i].deadline = p[i].D;
        p[i].completed = 0;
        U += (double)p[i].C / p[i].D;
    }

    if (U > 1.0)
        printf("\nScheduling not feasible (deadlines may be missed)\n");
    else
        printf("\nScheduling feasible\n");

    int t = 0, finished = 0;
    while (finished < n) {
        int chosen = -1;
        int minDeadline = 1e9;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival <= t && p[i].remaining > 0) {
                if (p[i].deadline < minDeadline) {
                    minDeadline = p[i].deadline;
                    chosen = i;
                }
            }
        }
        if (chosen == -1) {
            t++;
            continue;
        }
        printf("Time %2d: Executing Process %d\n", t, p[chosen].id);
        p[chosen].remaining--;
        if (p[chosen].remaining == 0) {
            p[chosen].completed = 1;
            finished++;
        }
        t++;
    }

    return 0;
}

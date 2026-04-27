#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int C;
    int remaining;
    int weight;
    int arrival;
    int completed;
} Process;

int main() {
    int n, TIME_QUANTUM;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter execution time (C), weight, arrival time for Process %d: ", i+1);
        scanf("%d %d %d", &p[i].C, &p[i].weight, &p[i].arrival);
        p[i].id = i+1;
        p[i].remaining = p[i].C;
        p[i].completed = 0;
        total_weight += p[i].weight;
    }

    printf("Enter TIME_QUANTUM: ");
    scanf("%d", &TIME_QUANTUM);

    int finished = 0, t = 0;
    while (finished < n) {
        int anyReady = 0;
        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].arrival <= t) {
                anyReady = 1;
                int time_slice = (double)p[i].weight / total_weight * TIME_QUANTUM;
                if (time_slice == 0) time_slice = 1;
                int run_time = (p[i].remaining < time_slice) ? p[i].remaining : time_slice;
                for (int k = 0; k < run_time; k++) {
                    printf("Time %2d: Executing Process %d\n", t, p[i].id);
                    t++;
                    p[i].remaining--;
                    if (p[i].remaining == 0) {
                        p[i].completed = 1;
                        finished++;
                        total_weight -= p[i].weight;
                        break;
                    }
                }
            }
        }
        if (!anyReady) {
            printf("Time %2d: CPU Idle\n", t);
            t++;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int id;
    int C;
    int T;
    int remaining;
    int nextRelease;
} Task;

int compare(const void *a, const void *b) {
    Task *t1 = (Task *)a;
    Task *t2 = (Task *)b;
    return t1->T - t2->T;
}

int main() {
    int n, hyperPeriod = 1;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    Task tasks[n];
    double U = 0.0;

    for (int i = 0; i < n; i++) {
        printf("Enter execution time (C) and period (T) for Task %d: ", i+1);
        scanf("%d %d", &tasks[i].C, &tasks[i].T);
        tasks[i].id = i+1;
        tasks[i].remaining = 0;
        tasks[i].nextRelease = 0;
        U += (double)tasks[i].C / tasks[i].T;
        hyperPeriod *= tasks[i].T;
    }

    double bound = n * (pow(2.0, 1.0/n) - 1);

    printf("\nCPU Utilization U = %.4f\n", U);
    printf("RMS Bound = %.4f\n", bound);

    if (U <= bound)
        printf("Schedulable using RMS\n");
    else
        printf("Not guaranteed schedulable (need further analysis)\n");

    qsort(tasks, n, sizeof(Task), compare);

    printf("\nTask priorities (smaller period = higher priority):\n");
    for (int i = 0; i < n; i++) {
        printf("Task %d: Period=%d, Execution=%d\n", tasks[i].id, tasks[i].T, tasks[i].C);
    }

    printf("\n--- Scheduling Simulation up to HyperPeriod=%d ---\n", hyperPeriod);
    for (int time = 0; time < hyperPeriod; time++) {
        for (int i = 0; i < n; i++) {
            if (time == tasks[i].nextRelease) {
                tasks[i].remaining = tasks[i].C;
                tasks[i].nextRelease += tasks[i].T;
            }
        }

        int chosen = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                chosen = i;
                break;
            }
        }

        if (chosen != -1) {
            printf("Time %2d: Executing Task %d\n", time, tasks[chosen].id);
            tasks[chosen].remaining--;
        } else {
            printf("Time %2d: CPU Idle\n", time);
        }
    }

    return 0;
}

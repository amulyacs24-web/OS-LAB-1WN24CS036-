#include <stdio.h>

struct Process {
    int pid, bt, at, prio, wt, tat, ct, rt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("Enter Arrival Time, Burst Time and Priority for P%d: ", i+1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prio);
        p[i].rt = p[i].bt;
    }

    int completed = 0, time = 0;
    int isCompleted[n];
    for(int i=0; i<n; i++) isCompleted[i] = 0;

    float totalTAT = 0, totalWT = 0;

    while(completed != n) {
        int idx = -1;
        int bestPrio = 1e9;

        // Pick process with highest priority (lowest number)
        for(int i=0; i<n; i++) {
            if(p[i].at <= time && isCompleted[i] == 0) {
                if(p[i].prio < bestPrio) {
                    bestPrio = p[i].prio;
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            p[idx].rt--;
            time++;
            if(p[idx].rt == 0) {
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                totalTAT += p[idx].tat;
                totalWT += p[idx].wt;

                isCompleted[idx] = 1;
                completed++;
            }
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tPrio\tCT\tTAT\tWT\n");
    for(int i=0; i<n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].prio,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT/n);
    printf("\nAverage Waiting Time    = %.2f\n", totalWT/n);

    return 0;
}

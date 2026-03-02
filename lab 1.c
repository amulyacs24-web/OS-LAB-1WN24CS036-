#include <stdio.h>

int main() {
    int n, bt[20], wt[20], tat[20], at[20], ct[20], p[20];
    int i, j, temp;
    float twt = 0.0, ttat = 0.0, awt, att;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Sort by Arrival Time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    // Calculate CT, WT, TAT
    ct[0] = at[0] + bt[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (i = 1; i < n; i++) {
        ct[i] = (ct[i-1] < at[i]) ? at[i] + bt[i] : ct[i-1] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    // Averages
    for (i = 0; i < n; i++) {
        twt += wt[i];
        ttat += tat[i];
    }
    awt = twt / n;
    att = ttat / n;

    // Output
    printf("\nPROCESS\tAT\tBT\tCT\tWT\tTAT");
    for (i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               p[i], at[i], bt[i], ct[i], wt[i], tat[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", att);

    return 0;
}

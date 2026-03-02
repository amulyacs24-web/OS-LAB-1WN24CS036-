#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[20][20], rowSum, colSum;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Row sums
    for (i = 0; i < r; i++) {
        rowSum = 0;
        for (j = 0; j < c; j++) {
            rowSum += a[i][j];
        }
        printf("Sum of row %d = %d\n", i + 1, rowSum);
    }

    // Column sums
    for (j = 0; j < c; j++) {
        colSum = 0;
        for (i = 0; i < r; i++) {
            colSum += a[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, colSum);
    }

    return 0;
}

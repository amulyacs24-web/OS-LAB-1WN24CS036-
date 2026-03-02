#include <stdio.h>

int main() {
    int n, i, j, count = 0;
    int a[50];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                break; // avoid counting same duplicates multiple times
            }
        }
    }

    printf("Total number of duplicate elements = %d\n", count);
    return 0;
}

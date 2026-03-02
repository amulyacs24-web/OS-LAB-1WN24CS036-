#include <stdio.h>

int main() {
    int n, i, first, second;
    int a[50];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    first = second = -99999; // initialize to very small

    for (i = 0; i < n; i++) {
        if (a[i] > first) {
            second = first;
            first = a[i];
        } else if (a[i] > second && a[i] != first) {
            second = a[i];
        }
    }

    if (second == -99999)
        printf("No second largest element found.\n");
    else
        printf("Second largest element = %d\n", second);

    return 0;
}

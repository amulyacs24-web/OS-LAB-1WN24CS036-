#include <stdio.h>
#include <limits.h>

int main() {
    int arr[100], n, i;
    int first = INT_MAX, second = INT_MAX;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        } else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MAX)
        printf("No second smallest element.\n");
    else
        printf("Second smallest element: %d\n", second);

    return 0;
}

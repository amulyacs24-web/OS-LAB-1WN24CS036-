#include <stdio.h>

int main() {
    int n, pos, i;
    int a[50];

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        for (i = pos - 1; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;

        printf("Array after deletion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}

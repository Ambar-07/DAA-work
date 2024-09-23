#include <stdio.h>

void insert(int arr[], int *n, int pos, int value) {
    if (pos < 0 || pos > *n) return;
    for (int i = *n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (pos < 0 || pos >= *n) return;
    for (int i = pos; i < *n - 1; i++) arr[i] = arr[i + 1];
    (*n)--;
}

int main() {
    int n, i, j, value, a1[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int k = 0; k < n; k++) scanf("%d", &a1[k]);

    printf("Enter the position to insert the element: ");
    scanf("%d", &i);
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    insert(a1, &n, i, value);

    printf("Array after insertion:\n");
    for (int k = 0; k < n; k++) printf("%d ", a1[k]);
    printf("\n");

    printf("Enter the position to delete the element: ");
    scanf("%d", &j);
    delete(a1, &n, j);

    printf("Array after deletion:\n");
    for (int k = 0; k < n; k++) printf("%d ", a1[k]);
    printf("\n");

    return 0;
}

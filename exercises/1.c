#include <stdio.h>

int sumArray(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = sumArray(arr, n);
    printf("Sum of all array elements: %d\n", sum);
    return 0;
}
#include <stdio.h>
#include <limits.h>

void findLargestThree(int arr[], int n) {
    if (n < 3) return;

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != first && arr[i] != second) {
            third = arr[i];
        }
    }

    printf("%d, %d, %d\n", first, second, third);
}

int main() {
    int arr[] = {10, 4, 3, 50, 23, 90};
    findLargestThree(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}

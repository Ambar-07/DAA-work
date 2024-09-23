#include <stdio.h>

void rearrange(int arr[], int n) {
    int temp[n], small = 0, large = n - 1, flag = 1;

    for (int i = 0; i < n; i++) {
        temp[i] = flag ? arr[large--] : arr[small++];
        flag = !flag;
    }

    for (int i = 0; i < n; i++)
        arr[i] = temp[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    rearrange(arr, n);

    printf("Rearranged array: \n");
    printArray(arr, n);

    return 0;
}

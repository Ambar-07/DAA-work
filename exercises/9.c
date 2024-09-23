#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int count = 0;  
    for (int i = 0; i < n; i++) 
        if (arr[i] != 0) 
            arr[count++] = arr[i]; 
    while (count < n) 
        arr[count++] = 0;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    printArray(arr, n);

    moveZeroesToEnd(arr, n);

    printf("Array after moving zeroes to the end: \n");
    printArray(arr, n);

    return 0;
}

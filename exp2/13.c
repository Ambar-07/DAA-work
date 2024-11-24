#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void findSecondLargestAndSmallest(int arr[], int n, int **secondLargest, int **secondSmallest) {
    int *largest = NULL, *smallest = NULL;
    *secondLargest = *secondSmallest = NULL;

    for (int i = 0; i < n; i++) {
        if (!largest || arr[i] > *largest) {
            *secondLargest = largest;
            largest = &arr[i];
        } else if (!*secondLargest || (arr[i] > **secondLargest && arr[i] < *largest)) {
            *secondLargest = &arr[i];
        }

        if (!smallest || arr[i] < *smallest) {
            *secondSmallest = smallest;
            smallest = &arr[i];
        } else if (!*secondSmallest || (arr[i] < **secondSmallest && arr[i] > *smallest)) {
            *secondSmallest = &arr[i];
        }
    }
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int *secondLargest, *secondSmallest;

    findSecondLargestAndSmallest(arr, n, &secondLargest, &secondSmallest);

    if (secondLargest && secondSmallest) {
        printf("Second Largest: %d\n", *secondLargest);
        printf("Second Smallest: %d\n", *secondSmallest);
        swap(secondLargest, secondSmallest);
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    } else {
        printf("Array does not have enough distinct elements.\n");
    }

    return 0;
}

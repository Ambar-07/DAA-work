#include <stdio.h>

void activitySelection(int start[], int finish[], int n) {
    int i, j;
    printf("Selected activities: ");
    i = 0;
    printf("(%d, %d)", start[i], finish[i]);
    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf(", (%d, %d)", start[j], finish[j]);
            i = j;
        }
    }
    printf("\n");
}

void sortActivities(int start[], int finish[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                int temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    sortActivities(start, finish, n);
    activitySelection(start, finish, n);
    return 0;
}

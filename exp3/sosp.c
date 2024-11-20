#include <stdio.h>

int subset[100];

void sumOfSubsets(int set[], int n, int sum, int index, int curr_sum) {
    if (curr_sum == sum) {
        for (int i = 0; i < index; i++) {
            if (subset[i] == 1) {
                printf("%d ", set[i]);
            }
        }
        printf("\n");
        return;
    }

    if (curr_sum > sum || index == n) {
        return;
    }

    subset[index] = 1;
    sumOfSubsets(set, n, sum, index + 1, curr_sum + set[index]);

    subset[index] = 0;
    sumOfSubsets(set, n, sum, index + 1, curr_sum);
}

int main() {
    int set[] = {10, 7, 5, 18, 12, 20, 15};
    int n = sizeof(set) / sizeof(set[0]);
    int sum = 35;

    sumOfSubsets(set, n, sum, 0, 0);

    return 0;
}

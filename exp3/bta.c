#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackBacktracking(int W, int wt[], int val[], int n, int index, int currValue, int currWeight, int *maxValue) {
    if (index == n || currWeight > W) {
        if (currWeight <= W && currValue > *maxValue) {
            *maxValue = currValue;
        }
        return;
    }

    // Include the current item
    knapsackBacktracking(W, wt, val, n, index + 1, currValue + val[index], currWeight + wt[index], maxValue);

    // Exclude the current item
    knapsackBacktracking(W, wt, val, n, index + 1, currValue, currWeight, maxValue);
}

int backtrackingKnapsack(int W, int wt[], int val[], int n) {
    int maxValue = 0;
    knapsackBacktracking(W, wt, val, n, 0, 0, 0, &maxValue);
    return maxValue;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

int compare(const void* a, const void* b) {
    double r1 = ((Item*)a)->ratio;
    double r2 = ((Item*)b)->ratio;
    return (r1 < r2) - (r1 > r2);
}

void greedyKnapsack(Item items[], int n, int W) {
    qsort(items, n, sizeof(Item), compare);
    int totalWeight = 0;
    double totalValue = 0;
    for (int i = 0; i < n && totalWeight < W; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item with value %d and weight %d\n", items[i].value, items[i].weight);
        }
    }
    printf("Total value (Greedy): %.2f\n", totalValue);
}

int main() {
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int W = 50;
    for (int i = 0; i < n; i++) {
        items[i].ratio = (double)items[i].value / items[i].weight;
    }
    greedyKnapsack(items, n, W);
    return 0;
}


//DP
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsackDP(int values[], int weights[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Total value (DP): %d\n", dp[n][W]);

    int w = W;
    printf("Items selected by DP approach:\n");
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item with value %d and weight %d\n", values[i - 1], weights[i - 1]);
            w -= weights[i - 1];
        }
    }
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = sizeof(values) / sizeof(values[0]);
    int W = 50;

    knapsackDP(values, weights, n, W);
    return 0;
}

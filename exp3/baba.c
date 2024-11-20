#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int level, profit, weight, bound;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int bound(Node u, int n, int W, int wt[], int val[]) {
    if (u.weight >= W) return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + wt[j] <= W)) {
        totweight += wt[j];
        profit_bound += val[j];
        j++;
    }

    if (j < n) profit_bound += (W - totweight) * val[j] / wt[j];
    return profit_bound;
}

int branchAndBoundKnapsack(int W, int wt[], int val[], int n) {
    Node queue[100];
    int front = 0, rear = 0;

    Node u, v;
    u.level = -1, u.profit = u.weight = 0;
    queue[rear++] = u;

    int maxProfit = 0;

    while (front < rear) {
        u = queue[front++];

        if (u.level == n - 1) continue;

        v.level = u.level + 1;

        v.weight = u.weight + wt[v.level];
        v.profit = u.profit + val[v.level];

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, wt, val);
        if (v.bound > maxProfit) queue[rear++] = v;

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, wt, val);
        if (v.bound > maxProfit) queue[rear++] = v;
    }
    return maxProfit;
}

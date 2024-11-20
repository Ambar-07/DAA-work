#include <stdio.h>
#include <limits.h>

void printOptimalParentheses(int i, int j, int n, int brackets[n][n], char *name) {
    if (i == j) {
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printOptimalParentheses(i, brackets[i][j], n, brackets, name);
    printOptimalParentheses(brackets[i][j] + 1, j, n, brackets, name);
    printf(")");
}

void matrixChainOrder(int p[], int n) {
    int dp[n][n];
    int brackets[n][n];
    for (int i = 1; i < n; i++) dp[i][i] = 0;
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }
    printf("Minimum number of multiplications: %d\n", dp[1][n - 1]);
    printf("Optimal Parentheses: ");
    char name = 'A';
    printOptimalParentheses(1, n - 1, n, brackets, &name);
    printf("\n");
}

int main() {
    int dimensions[] = {40, 20, 30, 10, 30};
    int size = sizeof(dimensions) / sizeof(dimensions[0]);
    matrixChainOrder(dimensions, size);
    return 0;
}

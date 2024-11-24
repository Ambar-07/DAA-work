#include <stdio.h>
#include <stdlib.h>

void multiplyMatrices(int *a, int *b, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0;
            for (int k = 0; k < c1; k++)
                *(result + i * c2 + j) += *(a + i * c1 + k) * *(b + k * c2 + j);
        }
}

void printMatrix(int *matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", *(matrix + i * cols + j));
        printf("\n");
    }
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Error! Column of first matrix should be equal to row of second matrix.\n");
        return -1;
    }

    int *a = (int *)malloc(r1 * c1 * sizeof(int));
    int *b = (int *)malloc(r2 * c2 * sizeof(int));
    int *result = (int *)malloc(r1 * c2 * sizeof(int));

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1 * c1; i++) scanf("%d", a + i);
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2 * c2; i++) scanf("%d", b + i);

    multiplyMatrices(a, b, result, r1, c1, c2);
    printf("Resultant matrix:\n");
    printMatrix(result, r1, c2);

    free(a);
    free(b);
    free(result);
    return 0;
}

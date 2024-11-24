#include <stdio.h>

int countNonZeroElements(int rows, int cols, int array[rows][cols]) {
    int count = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (array[i][j] != 0) count++;
    return count;
}

int main() {
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    int array[rows][cols];
    printf("Enter array elements:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &array[i][j]);

    printf("Total nonzero elements: %d\n", countNonZeroElements(rows, cols, array));
    return 0;
}

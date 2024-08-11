// C Program to print hollow square pattern using numbers
#include <stdio.h>
int main()
{
    int rows = 5;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            // statement to check boundry condition
            if (i > 0 && i < rows - 1 && j > 0
                && j < rows - 1) {
                printf("  ");
            }
            else {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }
    return 0;
}

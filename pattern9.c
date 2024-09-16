// C program to print the inverted full pyramid pattern o numbers
#include <stdio.h>
int main()
{
    int rows = 5;
    // first loop for printing all rows
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 2 * i; j++) {
            printf(" ");
        }
        for (int k = 0; k < 2 * (rows - i) - 1; k++) {
            printf("%d ", k + 1);
        }
        printf("\n");
    }
    
}

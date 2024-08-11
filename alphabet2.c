#include <stdio.h>

int main()
{
    int i, j, rows;
    printf("Enter the number of rows you want to print: ");
    scanf("%d", &rows);
    
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("%c", j + 64);
        }
        printf("\n");
    }
    
    return 0;
}


/*
Output
Enter the number of rows you want to print: 5
A
AB
ABC
ABCD
ABCDE
*/
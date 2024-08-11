#include<stdio.h>
int main()
{
    int i,j,rows;
    printf("enter the number of rows you wanna print: ");
    scanf("%d",&rows);
    for(i=1;i<=rows;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c",i+64);
        }
    printf("\n");
    }
}
/*
output
enter the number of rows you wanna print: 5
A
BB
CCC
DDDD
EEEEE
*/
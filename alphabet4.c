#include<stdio.h>
int main(){
    int i,j,rows; 
    printf("enter the rows you wanna print: ");
    scanf("%d",&rows);
    for(i=rows;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("%c",j+64);
        }
        printf("\n");
    }
}

/*
Output
ABCDE
ABCD
ABC
AB
A
*/
#include<stdio.h>
/*C program to print right half pyramid pattern of number */
int main()
{
    int n=5;
    for (int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("%d",j+1);
        }
        printf("\n");
    }
    return 0;
}
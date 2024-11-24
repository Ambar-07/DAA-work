#include <stdio.h>

int main(void) {
    int i, j, n, A;

    n = 10;

    for(i = 1; i <= n; i++) {
    
        for(A= 1; A <= n - i; A++) {
            printf("  ");
        }

        for(j = 1; j <= 2*i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}

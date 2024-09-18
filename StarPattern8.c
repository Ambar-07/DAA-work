#include <stdio.h>

int main(void) {
    int i, j, n = 10;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            if(j == 1 || j == i || i == n)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}

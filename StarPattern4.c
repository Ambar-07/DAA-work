
#include <stdio.h>

int main(void) {
    int i, j, n = 10;
    // Upper part
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    // Lower part
    for(i = n-1; i >= 1; i--) {
        for(j = 1; j <= n - i; j++) {
            printf("  ");
        }
        for(j = 1; j <= 2 * i - 1; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

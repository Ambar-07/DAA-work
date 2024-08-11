#include <stdio.h>

int main() {
    int rows = 5;
    int i, j, k;

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= rows - i; j++) {
            printf(" ");
        }

        for (k = 1; k <= i; k++) {
            printf("%c ", 'A' + i - 1);
        }

        printf("\n");
    }

    return 0;
}

/* Output
    A 
   B B
  C C C
 D D D D
E E E E E
*/
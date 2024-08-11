#include <stdio.h>

int main() {
    int rows = 5;
    char alphabet = 'E';

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c ", alphabet);
        }
        printf("\n");
        alphabet--;
    }

    return 0;
}

/* Output
E 
D D 
C C C 
B B B B 
A A A A A
*/
#include <stdio.h>

int main() {
    int rows = 5;
    char Char = 'A';

    for (int i = 0; i < rows; i++) {
        for (int j = i; j < rows; j++) {
            printf("%c ", Char + j);
        }
        printf("\n");
    }

    return 0;
}

/*
Output
A B C D E 
B C D E
C D E
D E
E
*/
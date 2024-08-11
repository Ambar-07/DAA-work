#include <stdio.h>

int main() {
    int rows = 5;
    int spaces = 0;
    char ch = 'A';

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < spaces; j++) {
            printf("  ");
        }

        for (int k = 0; k < rows - i; k++) {
            printf("%c ", ch++);
        }

        printf("\n");
        spaces++;
    }

    return 0;
}

/*
Output
A B C D E 
  F G H I
    J K L
      M N
        O
*/
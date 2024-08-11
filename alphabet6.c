#include <stdio.h>

int main() {
    char ch = 'A';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", ch);
            ch++;
        }
        printf("\n");
    }

    return 0;
}

/* Output
A B C D E 
F G H I J
K L M N O
P Q R S T
U V W X Y
*/
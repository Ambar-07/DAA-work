#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];

    printf("Enter an uppercase string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }

    printf("Lowercase string: %s", str);

    return 0;
}

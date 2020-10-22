#include <stdio.h>

int main() {
    char s[51];
    scanf("%[a-zA-Z ]", s);

    printf("Thank you, %s, and farewell!\n", s);
}
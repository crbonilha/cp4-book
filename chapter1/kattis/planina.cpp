#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int side = 2;
    while(n--) {
        side += side-1;
    }
    printf("%d\n", side*side);
}
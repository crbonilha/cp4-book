#include <stdio.h>

int main() {
    double x;
    scanf("%lf", &x);

    printf("%d\n", int(x * 1000.0 * (5280.0 / 4854.0) + 0.5));
}
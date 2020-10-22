#include <bits/stdc++.h>

int main() {
    int publish, impact;
    scanf("%d %d", &publish, &impact);

    printf("%d\n", publish == 1 ? impact : publish*(impact-1)+1);
}
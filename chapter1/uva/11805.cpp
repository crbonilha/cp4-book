#include <bits/stdc++.h>

int main() {
    int t;
    scanf("%d", &t);

    for(int tt=1; tt<=t; tt++) {
        int players, current, passes;
        scanf("%d %d %d", &players, &current, &passes);
        current--;

        while(passes--) {
            current = (current+1)%players;
        }

        printf("Case %d: %d\n", tt, current+1);
    }
}
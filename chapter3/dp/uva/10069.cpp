#include <bits/stdc++.h>
using namespace std;

const int MAXS = 10000;
const int MAXX = 100;
const int MAXD = 30;

int ss, sx;
char s[MAXS+1], x[MAXX+1];
int dp[MAXD][MAXS+1][MAXX+1];

void add(int s1, int x1, int s2, int x2) {
    for(int i=0; i<MAXD; i++) {
        int aux = dp[i][s1][x1] + dp[i][s2][x2];
        dp[i][s1][x1] = aux%10000;
        if(i+1 < MAXD) {
            dp[i+1][s1][x1] += aux/10000;
        }
    }
}

void solve(int ps, int px) {
    if(px == sx) {
        dp[0][ps][px] = 1;
        for(int i=1; i<MAXD; i++) {
            dp[i][ps][px] = 0;
        }
        return;
    }
    if(ps == ss) {
        for(int i=0; i<MAXD; i++) {
            dp[i][ps][px] = 0;
        }
        return;
    }

    int& ans = dp[0][ps][px];
    if(ans != -1) {
        return;
    }

    for(int i=0; i<MAXD; i++) {
        dp[i][ps][px] = 0;
    }

    solve(ps+1, px);
    add(ps, px, ps+1, px);

    if(s[ps] == x[px]) {
        solve(ps+1, px+1);
        add(ps, px, ps+1, px+1);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", s, x);
        ss = strlen(s);
        sx = strlen(x);

        memset(dp[0], -1, sizeof(dp[0]));
        solve(0, 0);

        int lastDigit = MAXD-1;
        while(lastDigit and dp[lastDigit][0][0] == 0) {
            lastDigit--;
        }
        printf("%d", dp[lastDigit][0][0]);
        for(lastDigit--; lastDigit>=0; lastDigit--) {
            printf("%04d", dp[lastDigit][0][0]);
        }
        printf("\n");
    }
}

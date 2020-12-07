#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAX = 50;

int units, bars, wide;

lli dp[2][MAX][MAX+1];
lli solve(bool prev, int u, int b) {
    if(u == units) {
        return b == bars;
    }

    lli& ans = dp[prev][u][b];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=1; i<=wide and u+i<=units; i++) {
        ans += solve(!prev, u+i, b+1);
    }
    return ans;
}

int main() {
    while(scanf("%d %d %d", &units, &bars, &wide) != EOF) {
        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(true, 0, 0));
    }
}

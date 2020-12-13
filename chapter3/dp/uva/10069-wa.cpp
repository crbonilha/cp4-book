#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAXS = 10000;
const int MAXX = 100;

int sn, xn;
char s[MAXS+1];
char x[MAXX+1];

lli dp[MAXS][MAXX];
lli solve(int ps, int px) {
    if(px == xn) {
        return 1;
    }
    if(ps == sn) {
        return 0;
    }

    lli& ans = dp[ps][px];
    if(ans != -1) {
        return ans;
    }

    ans = solve(ps+1, px);
    if(s[ps] == x[px]) {
        ans += solve(ps+1, px+1);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", s, x);
        sn = strlen(s);
        xn = strlen(x);

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(0, 0));
    }
}

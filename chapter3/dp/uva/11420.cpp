#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

int drawers;

lli dp[2][66][66];
lli solve(bool prevLocked, int drawer, int securedRem) {
    if(drawer == drawers) {
        return securedRem == 0;
    }

    lli& ans = dp[prevLocked][drawer][securedRem];
    if(ans != -1) {
        return ans;
    }

    ans = solve(false, drawer+1, securedRem); // unlocked
    if(securedRem or !prevLocked) {
        ans += solve(true, drawer+1, securedRem - prevLocked); // locked
    }
    return ans;
}

int main() {
    while(true) {
        int secured;
        scanf("%d %d", &drawers, &secured);
        if(drawers < 0) break;

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(true, 0, secured));
    }
}

#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

lli dp[85][2];
lli solve(int level, bool canBranch, int maxLevel) {
    if(level == maxLevel) {
        return 1;
    }

    lli& ans = dp[level][canBranch];
    if(ans != -1) {
        return ans;
    }

    if(!canBranch) {
        ans = solve(level+1, true, maxLevel);
    }
    else {
        ans = solve(level+1, false, maxLevel) + solve(level+1, true, maxLevel);
    }
    return ans;
}

int main() {
    while(true) {
        int n;
        scanf("%d", &n);
        if(n == 0) break;

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(1, false, n));
    }
}

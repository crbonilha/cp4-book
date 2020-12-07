#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAXN = 1000;

int n;
vector<lli> el;
lli m;

lli dp[MAXN][MAXN+1];
lli solve(int item, int used, int target) {
    if(item == n) {
        return used == target ? 1 : 0;
    }

    lli& ans = dp[item][used];
    if(ans != -1) {
        return ans;
    }

    if(target-used > n-item) {
        return ans = 0;
    }

    ans = solve(item+1, used, target);
    if(used < target) {
        ans = (ans + (el[item] * solve(item+1, used+1, target))) % m;
    }
    return ans;
}

int main() {
    while(true) {
        scanf("%d %lld", &n, &m);
        if(n == 0) break;

        el = vector<lli>(n);
        for(int i=0; i<n; i++) {
            scanf("%lld", &el[i]);
        }

        lli answer = 0;
        for(int k=1; k<=n; k++) {
            memset(dp, -1, sizeof(dp));
            answer = max(answer, solve(0, 0, k));
        }
        printf("%lld\n", answer);
    }
}

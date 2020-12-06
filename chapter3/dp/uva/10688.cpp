#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 500;

int n, k;

int dp[MAXN+1][MAXN+1];
int solve(int left, int right) {
    if(left >= right) {
        return 0;
    }

    int& ans = dp[left][right];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    for(int i=left; i<=right; i++) {
        int candidate = (right-left+1) * (i+k);
        candidate += solve(left, i-1);
        candidate += solve(i+1, right);
        ans = min(ans, candidate);
    }
    return ans;
}

int main() {
    int t, tt = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", tt++, solve(1, n));
    }
}

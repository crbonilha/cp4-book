#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int length;
int n;
vector<int> cuts;

int dp[53][53];
int solve(int l, int r) {
    if(l+1 == r) {
        return 0;
    }

    int& ans = dp[l][r];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    for(int i=l+1; i<r; i++) {
        ans = min(ans, solve(l, i) + solve(i, r) + cuts[r]-cuts[l]);
    }
    return ans;
}

int main() {
    while(true) {
        scanf("%d", &length);
        if(length == 0) break;

        scanf("%d", &n);

        cuts = vector<int>(n+2);
        cuts[0] = 0;
        cuts[n+1] = length;
        for(int i=1; i<=n; i++) {
            scanf("%d", &cuts[i]);
        }
        n += 2;

        memset(dp, -1, sizeof(dp));
        printf("The minimum cutting is %d.\n", solve(0, n-1));
    }
}

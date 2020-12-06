#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAXN = 20;

int n;

lli dp[MAXN+1][MAXN+1];
lli solve(int i, int j) {
    lli& ans = dp[i][j];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    if(i < j) {
        for(int k=i; k<j; k++) {
            ans = max(ans, solve(i, k) + solve(k+1, j));
        }
    }
    else {
        lli left = 0;
        if(i < n) {
            for(int k=i+1; k<=n; k++) {
                left = max(left, solve(k, 1) + solve(k, j));
            }
        }
        lli right = 0;
        if(j > 0) {
            for(int k=1; k<j; k++) {
                right = max(right, solve(i, k) + solve(n, k));
            }
        }
        ans = left + right;
    }
    return ans;
}

int main() {
    int aux;
    while(scanf("%d %d", &n, &aux) != EOF) {
        memset(dp, -1, sizeof(dp));
        dp[n][1] = aux;

        printf("%lld\n", solve(1, n));
    }
}

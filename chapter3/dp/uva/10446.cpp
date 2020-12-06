#include <bits/stdc++.h>
using namespace std;

using lli = unsigned long long int;

lli dp[61];
lli solve(int n, int back) {
    if(n <= 1) {
        return 1;
    }

    for(int i=2; i<=n; i++) {
        dp[i] = 1;
        for(int j=1; j<=back; j++) {
            if(i-j <= 1) {
                dp[i] += 1;
            }
            else {
                dp[i] += dp[i-j];
            }
        }
    }
    return dp[n];
}

int main() {
    int tt = 1;
    while(true) {
        int n, back;
        scanf("%d %d", &n, &back);
        if(n > 60) break;

        printf("Case %d: %llu\n", tt++, solve(n, back));
    }
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int dp[MAXN];

int main() {
    int b1, b2, t;
    while(scanf("%d %d %d", &b1, &b2, &t) != EOF) {
        for(int i=1; i<=t; i++) {
            dp[i] = -1;

            if(i >= b1 and dp[i-b1] != -1) {
                dp[i] = dp[i-b1]+1;
            }
            if(i >= b2 and dp[i-b2] != -1) {
                dp[i] = max(dp[i], dp[i-b2]+1);
            }
        }

        if(dp[t] >= 0) {
            printf("%d\n", dp[t]);
        }
        else {
            for(int i=t-1; i>=0; i--) {
                if(dp[i] >= 0) {
                    printf("%d %d\n", dp[i], t-i);
                    break;
                }
            }
        }
    }
}

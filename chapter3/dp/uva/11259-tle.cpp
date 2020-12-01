#include <bits/stdc++.h>
using namespace std;

const int COINS = 4;
const int MAX_V = 100000;

int coins[COINS];
int coinsAvlb[COINS];

int dp[COINS][MAX_V+1];
int solve(int coin, int val) {
    if(coin == COINS) {
        return val == 0;
    }

    int& ans = dp[coin][val];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=0; i <= coinsAvlb[coin] and val-i*coins[coin] >= 0; i++) {
        ans += solve(coin+1, val-i*coins[coin]);
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<COINS; i++) {
            scanf("%d", &coins[i]);
        }

        int q;
        scanf("%d", &q);
        while(q--) {
            for(int i=0; i<COINS; i++) {
                scanf("%d", &coinsAvlb[i]);
            }

            int v;
            scanf("%d", &v);

            memset(dp, -1, sizeof(dp));
            printf("%d\n", solve(0, v));
        }
    }
}

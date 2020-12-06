#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;

int n;
int wind[10][MAXN];

int dp[10][MAXN];
int solve(int alt, int pos) {
    if(pos == n) {
        return alt == 9 ? 0 : INF;
    }

    int& ans = dp[alt][pos];
    if(ans != -1) {
        return ans;
    }

    return ans = (-wind[alt][pos]) + min({
        solve(alt, pos+1) + 30,
        alt < 9 ? solve(alt+1, pos+1) + 60 : INF,
        alt > 0 ? solve(alt-1, pos+1) + 20 : INF
    });
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        n /= 100;

        for(int i=0; i<10; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &wind[i][j]);
            }
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n\n", solve(9, 0));
    }
}

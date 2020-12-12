#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 200000;

int n, c;
vector<int> stock;

int dp[2][MAXN];
int solve(bool has, int cur) {
    if(cur == n) {
        return 0;
    }

    int& ans = dp[has][cur];
    if(ans != INF) {
        return ans;
    }

    if(has) {
        ans = max(
            solve(true, cur+1),
            solve(false, cur+1)+stock[cur]-c
        );
    }
    else {
        ans = max(
            solve(true, cur+1)-stock[cur],
            solve(false, cur+1)
        );
    }
    return ans;
}

int main() {
    while(scanf("%d %d", &n, &c) != EOF) {
        stock = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &stock[i]);
        }

        memset(dp, 0x3f, sizeof(dp));
        printf("%d\n", solve(false, 0));
    }
}

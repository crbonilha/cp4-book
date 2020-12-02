#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> price;

int dp[1001][1000];
int solve(int cur, int prevJump) {
    if(cur == n) {
        return 0;
    }

    int& ans = dp[cur][prevJump];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    if(cur + prevJump + 1 <= n) {
        ans = min(ans, solve(cur+prevJump+1, prevJump+1) + price[cur+prevJump]);
    }
    if(cur - prevJump >= 1) {
        ans = min(ans, solve(cur-prevJump, prevJump) + price[cur-prevJump-1]);
    }
    return ans;
}

int main() {
    scanf("%d", &n);

    price = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &price[i]);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(1, 0));
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int goal, numbers;

int dp[MAX+1][MAX];
int solve(int sum, int k) {
    if(k == numbers) {
        return sum == goal;
    }

    int& ans = dp[sum][k];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=0; sum+i<=goal; i++) {
        ans += solve(sum+i, k+1);
        ans %= 1000000;
    }
    return ans;
}

int main() {
    while(true) {
        scanf("%d %d", &goal, &numbers);
        if(goal == 0 and numbers == 0) break;

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, 0));
    }
}

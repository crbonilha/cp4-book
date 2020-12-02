#include <bits/stdc++.h>
using namespace std;

int length, value;

int dp[27][27][1001];
int solve(int curLength, int curChar, int value) {
    if(curLength == length) {
        return value == 0;
    }

    int& ans = dp[curLength][curChar][value];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=curChar; i<26; i++) {
        ans += solve(curLength+1, i+1, value-i-1);
    }
    return ans;
}

int main() {
    int tt = 1;
    while(true) {
        scanf("%d %d", &length, &value);
        if(length == 0) break;

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", tt++, solve(0, 0, min(1000, value)));
    }
}

#include <bits/stdc++.h>
using namespace std;

int dp[1 << 12];
int solve(int state) {
    int& ans = dp[state];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=0; i<12; i++) {
        ans += !!(state&(1 << i));
    }

    for(int i=1; i<11; i++) {
        if(state&(1 << i)) {
            if(state&(1 << (i-1)) and !(state&(1 << (i+1)))) {
                ans = min(
                    ans,
                    solve(state - (1 << i) - (1 << (i-1)) + (1 << (i+1)))
                );
            }
            else if(state&(1 << (i+1)) and !(state&(1 << (i-1)))) {
                ans = min(
                    ans,
                    solve(state - (1 << i) - (1 << (i+1)) + (1 << (i-1)))
                );
            }
        }
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        char s[13];
        scanf("%s", s);

        int state = 0;
        for(int i=0; i<12; i++) {
            if(s[i] == 'o') {
                state |= (1 << i);
            }
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(state));
    }
}

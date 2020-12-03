#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAX_LENGTH = 100, MAX_ALPHA = 10;

int alpha, length;

lli dp[MAX_LENGTH][MAX_ALPHA];
lli solve(int pos, int prevAlpha) {
    if(pos == length) {
        return 1;
    }

    lli& ans = dp[pos][prevAlpha];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=-1; i<=1; i++) {
        int nextAlpha = prevAlpha+i;
        if(nextAlpha < 0 or nextAlpha > alpha) {
            continue;
        }

        ans += solve(pos+1, nextAlpha);
    }
    return ans;
}

lli getTotalWords(int alpha, int length) {
    lli ans = 1;
    for(int i=0; i<length; i++) {
        ans *= lli(alpha+1);
    }
    return ans;
}

int main() {
    while(scanf("%d %d", &alpha, &length) != EOF) {
        memset(dp, -1, sizeof(dp));
        lli valid = 0;
        for(int i=0; i<=alpha; i++) {
            valid += solve(1, i);
        }
        printf("%.9lf\n", 100.0*(double(valid)/double(getTotalWords(alpha, length))));
    }
}

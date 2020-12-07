#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAX_SUBJECTS = 70;

int subjects, goal, minScore;

lli dp[MAX_SUBJECTS][MAX_SUBJECTS+1];
lli solve(int subject, int score) {
    if(subject == subjects) {
        return score == goal;
    }

    lli& ans = dp[subject][score];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(int i=minScore; score+i<=goal; i++) {
        ans += solve(subject+1, score+i);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &subjects, &goal, &minScore);

        memset(dp, -1, sizeof(dp));
        printf("%lld\n", solve(0, 0));
    }
}

#include <bits/stdc++.h>
using namespace std;

const int MAX_H = 1000;

int n, l, p1, p2;
vector<int> holes;

int dp[MAX_H];
int solve(int hole) {
    if(hole == n) {
        return 0;
    }

    int& ans = dp[hole];
    if(ans != -1) {
        return ans;
    }

    int next;
    for(next=hole+1; next<n and holes[next]-holes[hole] <= p1; next++);
    ans = solve(next)+p1;

    for(next=hole+1; next<n and holes[next]-holes[hole] <= p2; next++);
    ans = min(ans, solve(next)+p2);

    return ans;
}

int main() {
    while(scanf("%d %d %d %d", &n, &l, &p1, &p2) != EOF) {
        holes = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &holes[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0));
    }
}

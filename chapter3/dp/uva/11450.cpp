#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200;
const int MAXC = 20;

int money, items;
vector<int> item[MAXC];

int dp[MAXN+1][MAXC];
int fn(int m, int c) {
    if(c == items) {
        return m;
    }

    int& ans = dp[m][c];
    if(ans != -1) {
        return ans;
    }

    for(int i=0; i<(int)item[c].size(); i++) {
        if(m+item[c][i] <= money) {
            ans = max(ans, fn(m+item[c][i], c+1));
        }
    }
    return ans;
}

int solve() {
    scanf("%d %d", &money, &items);

    for(int i=0; i<items; i++) {
        int k;
        scanf("%d", &k);

        item[i] = vector<int>(k);
        for(int j=0; j<k; j++) {
            scanf("%d", &item[i][j]);
        }
    }

    memset(dp, -1, sizeof(dp));
    return fn(0, 0);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int solution = solve();
        if(solution == -1) {
            printf("no solution\n");
        }
        else {
            printf("%d\n", solution);
        }
    }
}

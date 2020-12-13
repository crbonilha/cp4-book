#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 30;
const int MAXT = 300;

int t1, t2;
int n;
vector<int> cost[MAXN][2];

int dp[MAXN][MAXT+1][MAXT+1];
int nstep[MAXN][MAXT+1][MAXT+1];
int solve(int item, int remT1, int remT2) {
    if(item == n) {
        return 0;
    }

    int& ans = dp[item][remT1][remT2];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    for(int i=0; i<=(int)cost[item][0].size(); i++) {
        int left = i, right = (int)cost[item][0].size()-i;

        if(left <= remT1 and right <= remT2) {
            int candidate = solve(item+1, remT1-left, remT2-right)
                + (left ? cost[item][0][left-1] : 0)
                + (right ? cost[item][1][right-1] : 0);

            if(candidate < ans) {
                nstep[item][remT1][remT2] = left;
                ans = candidate;
            }
        }
    }
    return ans;
}

int main() {
    while(true) {
        scanf("%d %d", &t1, &t2);
        if(t1 == 0 and t2 == 0) break;

        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            int aux;
            scanf("%d", &aux);

            cost[i][0] = vector<int>(aux);
            for(int j=0; j<aux; j++) {
                scanf("%d", &cost[i][0][j]);
            }

            cost[i][1] = vector<int>(aux);
            for(int j=0; j<aux; j++) {
                scanf("%d", &cost[i][1][j]);
            }
        }

        memset(dp, -1, sizeof(dp));
        int ans = solve(0, t1, t2);
        printf("%d\n", ans);
        for(int item=0, left=t1, right=t2; item<n; item++) {
            printf("%d%c", nstep[item][left][right], " \n"[item == n-1]);

            int plusLeft = nstep[item][left][right];
            left -= plusLeft;
            right -= (int)cost[item][0].size()-plusLeft;
        }
        printf("\n");
    }
}

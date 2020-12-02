#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> d;

int dp[40][2001];
bool choiceUp[40][2001];
int solve(int step, int height) {
    if(step == n) {
        return height == 0 ? 0 : INF;
    }

    int& ans = dp[step][height];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    if(height >= d[step]) {
        int candidate = solve(step+1, height-d[step]);

        if(candidate != INF) {
            ans = max(height, candidate);
            choiceUp[step][height] = false;
        }
    }

    int candidate = solve(step+1, height+d[step]);
    if(candidate != INF and max(height, candidate) < ans) {
        ans = max(height, candidate);
        choiceUp[step][height] = true;
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        d = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d[i]);
        }

        memset(dp, -1, sizeof(dp));
        int answer = solve(0, 0);

        if(answer == INF) {
            printf("IMPOSSIBLE\n");
        }
        else {
            for(int i=0, height=0; i<n; i++) {
                if(choiceUp[i][height]) {
                    printf("U");
                    height += d[i];
                }
                else {
                    printf("D");
                    height -= d[i];
                }
            }
            printf("\n");
        }
    }
}

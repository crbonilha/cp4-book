#include <bits/stdc++.h>
using namespace std;

int tilesCount;
vector<int> tiles;

int dp[31][10001][31];
void solve(int tilesToPick, int target) {
    for(int i=0; i<=tilesCount; i++) {
        for(int k=0; k<=target; k++) {
            for(int j=0; j<=tilesToPick; j++) {
                if(k == 0 and j == 0) {
                    dp[i][k][j] = 1;
                }
                else if(i == 0 or k == 0 or j == 0) {
                    dp[i][k][j] = 0;
                }
                else {
                    dp[i][k][j] = dp[i-1][k][j];

                    if(k >= tiles[i-1]) {
                        dp[i][k][j] += dp[i-1][ k-tiles[i-1] ][j-1];
                    }
                }
            }
        }
    }
}

int bdp[31][31];
// k out of n
int binomial(int n, int k) {
    if(k > n) {
        return 0;
    }
    else if(k == 0 or k == n) {
        return 1;
    }

    if(bdp[n][k] != -1) {
        return bdp[n][k];
    }

    return bdp[n][k] = binomial(n-1, k-1) + binomial(n-1, k);
}

int getTotalStates(int n, int k) {
    memset(bdp, -1, sizeof(bdp));

    return binomial(n, k);
}

int main() {
    int t, tt = 1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &tilesCount);

        tiles = vector<int>(tilesCount);
        for(int i=0; i<tilesCount; i++) {
            scanf("%d", &tiles[i]);
        }

        int tilesToPick, target;
        scanf("%d %d", &tilesToPick, &target);

        solve(tilesToPick, target);

        int totalStates = getTotalStates(tilesCount, tilesToPick);
        int winningState = dp[tilesCount][target][tilesToPick];
        int losingState = totalStates - winningState;
        printf("Game %d -- %d : %d\n", tt++, winningState, losingState);
    }
}

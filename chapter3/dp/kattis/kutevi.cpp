#include <bits/stdc++.h>
using namespace std;

const int MAX_P = 10;
const int OK = 1, NOTOK = 2;

int n;
vector<int> pieces;

int dp[MAX_P][360];
int solve(int piece, int angle, int target) {
    if(piece == n) {
        return angle == target ? OK : NOTOK;
    }

    int& ans = dp[piece][angle];
    if(ans != -1) {
        return ans;
    }

    ans = solve(piece+1, angle, target);
    for(int i=1; (angle+i*pieces[piece])%360 != angle; i++) {
        int candidate = solve(piece+1, (angle+i*pieces[piece])%360, target);

        if(candidate == OK) {
            ans = OK;
            break;
        }
    }
    return ans;
}

int main() {
    int q;
    scanf("%d %d", &n, &q);

    pieces = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &pieces[i]);
    }

    while(q--) {
        int target;
        scanf("%d", &target);

        memset(dp, -1, sizeof(dp));
        printf("%s\n", solve(0, 0, target) == OK ? "YES" : "NO");
    }
}

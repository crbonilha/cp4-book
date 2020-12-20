#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;
const int MAXS = 100;

int powers;
char powerName[MAXN][MAXS+1];
ii power[MAXN]; // attack, consumption

int villains;
int villainDefense[MAXN];
bool villainWeakness[MAXN][MAXN];
char aux[MAXN*(MAXS+1)];

int matchPower(char * s) {
    for(int i=0; i<powers; i++) {
        if(!strcmp(powerName[i], s)) {
            return i;
        }
    }
    return 0;
}

int dp[MAXN][MAXN];
int solve(int p, int e) {
    if(e == villains) {
        return 0;
    }
    if(p == powers) {
        return INF;
    }

    int& ans = dp[p][e];
    if(ans != -1) {
        return ans;
    }

    ans = solve(p+1, e);
    if(villainWeakness[p][e] and power[p].first >= villainDefense[e]) {
        ans = min(
            ans,
            solve(p+1, e+1) + power[p].second
        );
    }
    return ans = min(ans, INF);
}

int main() {
    int energy;
    while(true) {
        scanf("%d %d %d", &powers, &villains, &energy);
        if(powers == 0 and villains == 0 and energy == 0) break;

        for(int i=0; i<powers; i++) {
            scanf("%s %d %d", powerName[i], &power[i].first, &power[i].second);
        }

        memset(villainWeakness, false, sizeof(villainWeakness));
        for(int i=0; i<villains; i++) {
            char villainName[MAXS+1];
            scanf("%s %d %s", villainName, &villainDefense[i], aux);

            int size = strlen(aux);
            char auxPower[MAXS+1];
            int powerIndex = 0;
            for(int j=0; j<=size; j++) {
                if(j == size or aux[j] == ',') {
                    auxPower[powerIndex] = 0;
                    villainWeakness[ matchPower(auxPower) ][i] = true;
                    powerIndex = 0;
                }
                else {
                    auxPower[powerIndex++] = aux[j];
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        printf("%s\n", solve(0, 0) <= energy ? "Yes" : "No");
    }
}

#include <bits/stdc++.h>
using namespace std;

const int MAX_RES = 200, MAX_DEPOTS = 30, INF = 0x3f3f3f3f;

int restaurants, depots;
vector<int> resPos;

int countDist(int prevDepot, int nextDepot) {
    int answer = 0;
    if(prevDepot == -1 and nextDepot == -1) {
        answer = INF;
    }
    else if(prevDepot == -1) {
        for(int i=0; i<=nextDepot; i++) {
            answer += resPos[nextDepot]-resPos[i];
        }
    }
    else if(nextDepot == -1) {
        for(int i=prevDepot; i<restaurants; i++) {
            answer += resPos[i]-resPos[prevDepot];
        }
    }
    else {
        for(int i=prevDepot; i<=nextDepot; i++) {
            answer += min(
                resPos[i]-resPos[prevDepot],
                resPos[nextDepot]-resPos[i]
            );
        }
    }
    return answer;
}

int dp[MAX_RES][MAX_RES+1][MAX_DEPOTS+1];
bool placeDepot[MAX_RES][MAX_RES+1][MAX_DEPOTS+1];
int solve(int curRes, int prevDepot, int placedDepots) {
    if(curRes == restaurants) {
        return countDist(prevDepot, -1);
    }

    int& ans = dp[curRes][prevDepot+1][placedDepots];
    if(ans != -1) {
        return ans;
    }

    ans = solve(curRes+1, prevDepot, placedDepots);

    if(placedDepots < depots) {
        int candidate = solve(curRes+1, curRes, placedDepots+1) + countDist(prevDepot, curRes);

        if(candidate < ans) {
            ans = candidate;
            placeDepot[curRes][prevDepot+1][placedDepots] = true;
        }
    }

    return ans;
}

vector<int> getDepotsRestaurantsServed(vector<int> placements) {
    vector<int> ans((int)placements.size(), 0);
    for(int i=0; i<restaurants; i++) {
        int closest = 0;
        for(int j=1; j<(int)placements.size(); j++) {
            if(abs(resPos[i] - resPos[ placements[j] ]) < abs(resPos[i] - resPos[ placements[closest] ])) {
                closest = j;
            }
        }
        ans[closest]++;
    }
    return ans;
}

int main() {
    int tt = 1;
    while(true) {
        scanf("%d %d", &restaurants, &depots);
        if(restaurants == 0) break;

        resPos = vector<int>(restaurants);
        for(int i=0; i<restaurants; i++) {
            scanf("%d", &resPos[i]);
        }

        memset(dp, -1, sizeof(dp));
        memset(placeDepot, false, sizeof(placeDepot));

        int answer = solve(0, -1, 0);
        vector<int> placements;
        for(int i=0, prevDepot=-1, totalDepots=0; i<restaurants; i++) {
            if(placeDepot[i][prevDepot+1][totalDepots]) {
                placements.push_back(i);
                prevDepot = i;
                totalDepots++;
            }
        }
        printf("Chain %d\n", tt++);
        vector<int> depotsRestaurantsServed = getDepotsRestaurantsServed(placements);
        for(int i=0, prevRes=1; i<(int)placements.size(); i++) {
            printf("Depot %d at restaurant %d serves restaurant", i+1, placements[i]+1);
            if(depotsRestaurantsServed[i] == 1) {
                printf(" %d\n", prevRes);
            }
            else {
                printf("s %d to %d\n", prevRes, prevRes+depotsRestaurantsServed[i]-1);
            }
            prevRes += depotsRestaurantsServed[i];
        }
        printf("Total distance sum = %d\n\n", answer);
    }
}

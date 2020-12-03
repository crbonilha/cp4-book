#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAX_RES = 200, MAX_DEPOTS = 30, INF = 0x3f3f3f3f;

int rests, depots;
vector<int> pos;

int dp[MAX_RES][MAX_RES+1][MAX_DEPOTS+1];
ii nextDepot[MAX_RES][MAX_RES+1][MAX_DEPOTS+1];
int solve(int leftRes, int rightRes, int depotsRem) {
    if(leftRes+1 == rightRes) {
        return 0;
    }

    int& ans = dp[leftRes][rightRes][depotsRem];
    if(ans != -1) {
        return ans;
    }

    if(depotsRem == 0) {
        ans = 0;
        for(int i=leftRes+1; i<rightRes; i++) {
            ans += min(
                pos[i]-pos[leftRes],
                pos[rightRes]-pos[i]
            );
        }
    }
    else {
        ans = INF;
        for(int i=leftRes+1; i<rightRes; i++) {
            for(int j=0; j<=depotsRem-1; j++) {
                int candidate = solve(leftRes, i, j) + solve(i, rightRes, depotsRem-j-1);
                
                if(candidate < ans) {
                    nextDepot[leftRes][rightRes][depotsRem] = {i, j};
                    ans = candidate;
                }
            }
        }
    }
    return ans;
}

int placeOuterRes(int leftRes, int rightRes, int depotsRem) {
    int answer = 0;
    for(int i=0; i<leftRes; i++) {
        answer += pos[leftRes]-pos[i];
    }
    for(int i=rightRes+1; i<rests; i++) {
        answer += pos[i]-pos[rightRes];
    }
    return answer + solve(leftRes, rightRes, depotsRem);
}

void populatePlacements(vector<int>& placements, int leftRes, int rightRes, int depotsRem) {
    if(leftRes+1 == rightRes) {
        return;
    }

    if(depotsRem == 0) {
        return;
    }

    placements.push_back(nextDepot[leftRes][rightRes][depotsRem].first);

    populatePlacements(placements, leftRes, nextDepot[leftRes][rightRes][depotsRem].first, nextDepot[leftRes][rightRes][depotsRem].second);
    populatePlacements(placements, nextDepot[leftRes][rightRes][depotsRem].first, rightRes, depotsRem-nextDepot[leftRes][rightRes][depotsRem].second-1);
}

vector<int> getRestsPerDepot(vector<int>& placements) {
    vector<int> ans((int)placements.size(), 0);
    for(int i=0; i<rests; i++) {
        int closest = 0;
        for(int j=1; j<(int)placements.size(); j++) {
            if(abs(pos[i]-pos[ placements[j] ]) < abs(pos[i]-pos[ placements[closest] ])) {
                closest = j;
            }
        }
        ans[closest]++;
    }
    return ans;
}

int main() {
    int tt=1;
    while(true) {
        scanf("%d %d", &rests, &depots);
        if(rests == 0) break;

        pos = vector<int>(rests);
        for(int i=0; i<rests; i++) {
            scanf("%d", &pos[i]);
        }

        printf("Chain %d\n", tt++);

        if(depots == 1) {
            int answer = INF, placement;
            for(int i=0; i<rests; i++) {
                int candidate = 0;
                for(int j=0; j<rests; j++) {
                    candidate += abs(pos[i]-pos[j]);
                }
                if(candidate < answer) {
                    answer = candidate;
                    placement = i;
                }
            }
            printf("Depot %d at restaurant %d serves restaurant", 1, placement+1);
            if(rests == 1) {
                printf(" %d\n", 1);
            }
            else {
                printf("s %d to %d\n", 1, rests);
            }
            printf("Total distance sum = %d\n\n", answer);
            continue;
        }

        memset(dp, -1, sizeof(dp));

        ii answer = {0, rests-1};
        for(int i=0; i<rests; i++) {
            for(int j=i+1; j<rests; j++) {
                if(placeOuterRes(i, j, depots-2) < placeOuterRes(answer.first, answer.second, depots-2)) {
                    answer = {i, j};
                }
            }
        }

        vector<int> placements;
        placements.push_back(answer.first);
        placements.push_back(answer.second);
        populatePlacements(placements, answer.first, answer.second, depots-2);
        sort(placements.begin(), placements.end());

        vector<int> restsPerDepots = getRestsPerDepot(placements);
        for(int i=0, prevRes=1; i<(int)restsPerDepots.size(); i++) {
            printf("Depot %d at restaurant %d serves restaurant", i+1, placements[i]+1);

            if(restsPerDepots[i] == 1) {
                printf(" %d\n", prevRes);
            }
            else {
                printf("s %d to %d\n", prevRes, prevRes+restsPerDepots[i]-1);
            }
            prevRes += restsPerDepots[i];
        }
        
        printf("Total distance sum = %d\n\n", placeOuterRes(answer.first, answer.second, depots-2));
    }
}

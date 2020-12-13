#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MAXC = 100;
const int MAXT = 1000;
const int MAXTS = 100;

int cities;
char cityName[MAXC][128];

vector<ii> train[MAXT]; // moment, city
vector<ii> cityTrain[MAXT]; // moment, train

int getCity(char* s) {
    for(int i=0; i<cities; i++) {
        if(strcmp(cityName[i], s) == 0) {
            return i;
        }
    }
    return 0;
}

int dp[MAXT][MAXTS];
int solve(int t, int tStop, int goal) {
    if(train[t][tStop].second == goal) {
        return train[t][tStop].first;
    }

    int& ans = dp[t][tStop];
    if(ans != -1) {
        return ans;
    }
    ans = INF;

    // stay in the train
    if(tStop+1 < (int)train[t].size()) {
        ans = solve(t, tStop+1, goal);
    }

    // stay in the city
    int curTrain = lower_bound(
        cityTrain[ train[t][tStop].second ].begin(),
        cityTrain[ train[t][tStop].second ].end(),
        ii(train[t][tStop].first, -1)) - cityTrain[ train[t][tStop].second ].begin();
    for(int i=curTrain; i<(int)cityTrain[ train[t][tStop].second ].size(); i++) {
        if(cityTrain[ train[t][tStop].second ][i].second == t) {
            if(i+1 < (int)cityTrain[ train[t][tStop].second ].size()) {
                ans = min(
                    ans,
                    solve(
                        cityTrain[ train[t][tStop].second ][i+1].second,
                        lower_bound(
                            train[ cityTrain[ train[t][tStop].second ][i+1].second ].begin(),
                            train[ cityTrain[ train[t][tStop].second ][i+1].second ].end(),
                            ii(train[t][tStop].first, -1)
                        ) - train[ cityTrain[ train[t][tStop].second ][i+1].second ].begin(),
                        goal
                    )
                );
            }
            break;
        }
    }

    return ans;
}

int main() {
    int t, tt=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &cities);
        for(int i=0; i<cities; i++) {
            scanf("%s", cityName[i]);
        }

        for(int i=0; i<cities; i++) {
            cityTrain[i].clear();
        }

        int trains;
        scanf("%d", &trains);
        for(int i=0; i<trains; i++) {
            int qty;
            scanf("%d", &qty);

            train[i] = vector<ii>(qty);
            for(int j=0; j<qty; j++) {
                char aux[128];
                scanf("%d %s", &train[i][j].first, aux);
                train[i][j].second = getCity(aux);

                cityTrain[ train[i][j].second ].push_back({train[i][j].first, i});
            }
        }

        for(int i=0; i<cities; i++) {
            sort(cityTrain[i].begin(), cityTrain[i].end());
        }

        int startTime;
        char startCity[128], endCity[128];
        int startCityId, endCityId;
        scanf("%d %s %s", &startTime, startCity, endCity);
        startCityId = getCity(startCity);
        endCityId = getCity(endCity);

        memset(dp, -1, sizeof(dp));
        ii ans = {INF, INF};
        for(int i=0; i<trains; i++) {
            for(int j=0; j<(int)train[i].size(); j++) {
                if(train[i][j].second == startCityId and train[i][j].first >= startTime) {
                    ans = min(ans, {solve(i, j, endCityId), -train[i][j].first});
                }
            }
        }
        printf("Scenario %d\n", tt++);
        if(ans.first == INF) {
            printf("No connection\n");
        }
        else {
            printf("Departure %04d %s\n", -ans.second, startCity);
            printf("Arrival   %04d %s\n", ans.first, endCity);
        }
        printf("\n");
    }
}
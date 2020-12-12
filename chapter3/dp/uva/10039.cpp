#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MAXC = 100;
const int MAXT = 1000;

int cities;
char cityName[MAXC][128];

int trains;
vector<ii> train[MAXT]; // moment, city

vector<pair<int, ii> > cityTimeline[MAXC]; // moment, train, trainStop

int getCity(char *s) {
    for(int i=0; i<cities; i++) {
        if(strcmp(cityName[i], s) == 0) {
            return i;
        }
    }
    return 0;
}

int dp[MAXC][MAXT*MAXC];
int solve(int city, int stop, int goal) {
    if(city == goal) {
        return cityTimeline[city][stop].first;
    }

    int& ans = dp[city][stop];
    if(ans != -1) {
        return ans;
    }
    ans = INF;

    // stay on the current train.
    if(cityTimeline[city][stop].second.second+1 < (int)train[ cityTimeline[city][stop].second.first ].size()) {
        // ans = solve(
        //     train[ cityTimeline[city][stop].second.second+1 ].second,
        // );
    }
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
            cityTimeline[i].clear();
        }

        scanf("%d", &trains);
        for(int i=0; i<trains; i++) {
            int k;
            scanf("%d", &k);

            train[i] = vector<ii>(k);
            for(int j=0; j<k; j++) {
                char aux[128];
                scanf("%d %s", &train[i][j].first, aux);

                train[i][j].second = getCity(aux);

                cityTimeline[ train[i][j].second ].push_back({train[i][j].first, {i, j}});
            }
        }

        for(int i=0; i<cities; i++) {
            sort(cityTimeline[i].begin(), cityTimeline[i].end());
        }

        int startTime;
        scanf("%d", &startTime);

        char startCity[128], endCity[128];
        int startCityId, endCityId;
        scanf("%s %s", startCity, endCity);
        startCityId = getCity(startCity);
        endCityId = getCity(endCity);

        memset(dp, -1, sizeof(dp));

        ii ans = {INF, INF};
        for(int i=0; i<(int)cityTimeline[startCityId].size(); i++) {
            ans = min(
                ans,
                {solve(startCityId, i, endCityId), cityTimeline[startCityId][i].first}
            );
        }

        printf("Scenario %d\n", tt++);
        if(ans.first == INF) {
            printf("No connection\n");
        }
        else {
            printf("Departure %04d %s\n", ans.second, startCity);
            printf("Arrival   %04d %s\n", ans.first, endCity);
        }
        printf("\n");
    }
}

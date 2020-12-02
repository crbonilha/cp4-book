#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAX_TRIPS = 100;

int trips;
vector<ii> info; // duration, spheres

int dp[MAX_TRIPS][MAX_TRIPS+1];
int solve(int trip, int spheres) {
    if(trip == trips) {
        return 0;
    }

    int& ans = dp[trip][spheres];
    if(ans != -1) {
        return ans;
    }

    ans = solve(trip+1, min(MAX_TRIPS, spheres+info[trip].second)) + info[trip].first;

    if(spheres) {
        ans = min(ans, solve(trip+1, min(MAX_TRIPS, spheres+info[trip].second-1)) + info[trip].first/2);
    }

    return ans;
}

int main() {
    while(true) {
        scanf("%d", &trips);
        if(trips == 0) break;

        info = vector<ii>(trips);
        for(int i=0; i<trips; i++) {
            scanf("%d %d", &info[i].first, &info[i].second);
        }

        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(0, 0));
    }
}

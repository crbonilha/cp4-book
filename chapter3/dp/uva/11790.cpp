#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;

int n;
vector<ii> buildings; // height, width
vector<lli> dp;

lli findLIS(vector<ii>& b) {
    for(int i=0; i<(int)b.size(); i++) {
        dp[i] = b[i].second;

        for(int j=i-1; j>=0; j--) {
            if(b[i].first > b[j].first) {
                dp[i] = max(dp[i], dp[j]+b[i].second);
            }
        }
    }

    lli answer = 0;
    for(lli candidate : dp) {
        answer = max(answer, candidate);
    }
    return answer;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        printf("Case %d. ", tt);

        scanf("%d", &n);

        buildings = vector<ii>(n);
        dp = vector<lli>(n);

        for(int i=0; i<n; i++) {
            scanf("%lld", &buildings[i].first);
        }
        for(int i=0; i<n; i++) {
            scanf("%lld", &buildings[i].second);
        }

        lli increasing = findLIS(buildings);
        reverse(buildings.begin(), buildings.end());
        lli decreasing = findLIS(buildings);

        if(increasing >= decreasing) {
            printf("Increasing (%lld). Decreasing (%lld).\n", increasing, decreasing);
        }
        else {
            printf("Decreasing (%lld). Increasing (%lld).\n", decreasing, increasing);
        }
    }
}

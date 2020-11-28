#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int n;
vector<ii> buildings; // height, width

bool myComp(const pair<ii, int>& a, const pair<ii, int>& b) {
    return a.first.first < b.first.first;
}

int findLis() {
    vector<pair<ii, int> > lis;

    int it = 1;
    for(ii building : buildings) {
        int pos = lower_bound(lis.begin(), lis.end(), pair<ii, int>(building, 0), myComp) - lis.begin();

        int lisValue = building.second + (pos ? lis[pos-1].second : 0);

        if(pos < (int)lis.size()) {
            if(building.first < lis[pos].first.first or building.second > lis[pos].first.second) {
                lis[pos] = {building, lisValue};
            }
        }
        else {
            lis.push_back({building, lisValue});
        }
    }

    int answer = 0;
    for(auto lisIt : lis) {
        answer = max(answer, lisIt.second);
    }
    return answer;
}

int main() {
    int t;
    scanf("%d", &t);
    for(int tt=1; tt<=t; tt++) {
        scanf("%d", &n);

        buildings = vector<ii>(n);

        for(int i=0; i<n; i++) {
            scanf("%d", &buildings[i].first);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &buildings[i].second);
        }

        int increasing = findLis();
        reverse(buildings.begin(), buildings.end());
        int decreasing = findLis();

        if(increasing >= decreasing) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", tt, increasing, decreasing);
        }
        else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", tt, decreasing, increasing);
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int n;
vector<ii> buildings;

int sortFn(const int& a, const int& b) {
    if(buildings[a].first == buildings[b].first) {
        return a > b;
    }
    return buildings[a].first <= buildings[b].first;
}

int getBit(vector<int>& bit, int index) {
    index++;

    int answer = 0;
    while(index) {
        answer = max(answer, bit[index]);
        index -= index & (-index);
    }
    return answer;
}
void updateBit(vector<int>& bit, int index, int value) {
    index++;

    while(index <= n) {
        bit[index] = max(bit[index], value);
        index += index & (-index);
    }
}

int getLis() {
    vector<int> p(n);
    for(int i=0; i<n; i++) {
        p[i] = i;
    }
    sort(p.begin(), p.end(), sortFn);

    vector<int> bit(n+1, 0);

    for(int i=0; i<n; i++) {
        int lisSoFar = getBit(bit, p[i]-1);

        updateBit(bit, p[i], lisSoFar + buildings[ p[i] ].second);
    }

    return getBit(bit, n-1);
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

        int increasing = getLis();
        reverse(buildings.begin(), buildings.end());
        int decreasing = getLis();

        if(increasing >= decreasing) {
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", tt, increasing, decreasing);
        }
        else {
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", tt, decreasing, increasing);
        }
    }
}

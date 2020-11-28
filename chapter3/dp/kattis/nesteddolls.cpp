#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 100010;

int n;
ii v[MAXN];
int lis[MAXN];

int findLis() {
    int lisSize = 0;
    lis[lisSize++] = v[0].second;

    for(int i=1; i<n; i++) {
        if(v[i].second > lis[0]) {
            lis[0] = v[i].second;
        }
        else if(v[i].second <= lis[lisSize-1]) {
            lis[lisSize++] = v[i].second;
        }
        else {
            int pos = upper_bound(lis, lis+lisSize, v[i].second, greater<int>()) - lis;
            lis[pos] = v[i].second;
        }
    }

    return lisSize;
}

bool sortfn(const ii& a, const ii& b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        for(int i=0; i<n; i++) {
            scanf("%d %d", &v[i].first, &v[i].second);
        }
        sort(v, v+n, sortfn);

        printf("%d\n", findLis());
    }
}

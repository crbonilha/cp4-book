// doesnt work

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 100000;

int n;
ii v[MAXN];
int bit[MAXN+1];
int p[MAXN];

void setBit(int index, int value) {
    while(index <= n) {
        bit[index] = max(bit[index], value);
        index += index&-index;
    }
}
int getBit(int index) {
    int answer = 0;
    while(index) {
        answer = max(answer, bit[index]);
        index -= index&-index;
    }
    return answer;
}

bool sortfn2(const int& a, const int& b) {
    if(v[a].second == v[b].second) {
        return a > b;
    }
    return v[a].second > v[b].second;
}

int getLis() {
    for(int i=0; i<n; i++) {
        p[i] = i;
    }
    sort(p, p+n, sortfn2);

    for(int i=0; i<n; i++) {
        setBit(p[i]+1, getBit(p[i]+1)+1);
    }
    return getBit(n);
}

bool sortfn(const ii& a, const ii& b) {
    if(a.first == b.first) {
        return a.second >= b.second;
    }
    return a.first < b.first;
}

int solve() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d %d", &v[i].first, &v[i].second);

        bit[i+1] = 0;
    }
    sort(v, v+n, sortfn);

    return getLis();
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%d\n", solve());
    }
}

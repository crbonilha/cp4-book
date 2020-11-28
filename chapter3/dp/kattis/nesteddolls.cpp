#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int n;
vector<ii> v;
vector<bool> visited;

void visitLis(vector<int>& parent, int u) {
    if(parent[u] != -1) {
        visitLis(parent, parent[u]);
    }
    visited[u] = true;
}

int findLis() {
    vector<int> lis, lisId, parent = vector<int>(n);

    for(int i=0; i<n; i++) {
        if(visited[i]) {
            continue;
        }

        int pos = lower_bound(lis.begin(), lis.end(), v[i].second) - lis.begin();

        if(pos < (int)lis.size()) {
            lis[pos] = v[i].second;
            lisId[pos] = i;
        }
        else {
            lis.push_back(v[i].second);
            lisId.push_back(i);
        }

        parent[i] = pos ? lisId[pos-1] : -1;
    }

    visitLis(parent, lisId[ (int)lisId.size()-1 ]);

    return (int)lis.size();
}

bool sortfn(const ii& a, const ii& b) {
    if(a.first == b.first) {
        return a.second >= b.second;
    }
    return a.first < b.first;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        v = vector<ii>(n);
        visited = vector<bool>(n, false);

        for(int i=0; i<n; i++) {
            scanf("%d %d", &v[i].first, &v[i].second);
        }
        sort(v.begin(), v.end(), sortfn);

        int removed = 0, iterations = 0;
        while(removed < n) {
            removed += findLis();
            iterations++;
        }
        printf("%d\n", iterations);
    }
}

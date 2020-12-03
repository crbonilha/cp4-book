#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 100000;

int n;
vector<ii> adj[MAXN];

int f;
vector<int> friends;
map<int, bool> landmarkHasFriend;

int total;
int dist[MAXN];
bool dfs(int u, int cur) {
    dist[u] = cur;

    bool foundFriend = false;

    if(landmarkHasFriend[u]) {
        foundFriend = true;
    }

    for(ii v : adj[u]) {
        if(dfs(v.first, cur+v.second)) {
            foundFriend = true;
            total += v.second;
        }
    }

    return foundFriend;
}

int main() {
    while(scanf("%d %d", &n, &f) != EOF) {
        for(int i=0; i<n; i++) {
            adj[i].clear();
        }

        for(int i=0; i<n-1; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a--; b--;

            adj[a].push_back({b, c});
        }

        landmarkHasFriend.clear();

        friends = vector<int>(f);
        for(int i=0; i<f; i++) {
            scanf("%d", &friends[i]);
            friends[i]--;

            landmarkHasFriend[ friends[i] ] = true;
        }

        total = 0;
        dfs(0, 0);

        int maxDist = dist[ friends[0] ];
        for(int i=1; i<f; i++) {
            maxDist = max(maxDist, dist[ friends[i] ]);
        }

        printf("%d\n", total - maxDist);
    }
}

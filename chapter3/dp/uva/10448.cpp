#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

using ii = pair<int, int>;

int n;
vector<ii> adj[51];
bool visi[51];

bool dfs(vector<int>& path, int u, int p, int goal) {
    if(u == goal) {
        return true;
    }

    for(ii v : adj[u]) {
        if(v.first == p) {
            continue;
        }
        if(dfs(path, v.first, u, goal)) {
            path.push_back(v.second);
            return true;
        }
    }

    return false;
}

int dp[50][100001];
int solve(vector<int>& path, int u, int budget) {
    if(u == (int)path.size()) {
        return budget == 0 ? 0 : INF;
    }

    int& ans = dp[u][budget];
    if(ans != -1) {
        return ans;
    }

    ans = solve(path, u+1, budget);
    
    if(budget-2*path[u] >= 0) {
        ans = min(ans, solve(path, u, budget-2*path[u])+2);
    }

    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int m;
        scanf("%d %d", &n, &m);

        for(int i=1; i<=n; i++) {
            adj[i].clear();
        }

        for(int i=0; i<m; i++) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);

            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int q;
        scanf("%d", &q);
        while(q--) {
            int u, v, c;
            scanf("%d %d %d", &u, &v, &c);

            vector<int> path = vector<int>();
            dfs(path, u, u, v);

            int minCost = 0;
            for(int i=0; i<(int)path.size(); i++) {
                minCost += path[i];
            }
            path.erase(path.begin());

            if(minCost > c) {
                printf("No\n");
                continue;
            }

            memset(dp, -1, sizeof(dp));
            int answer = solve(path, 0, c-minCost);
            if(answer < INF) {
                printf("Yes %d\n", answer + (int)path.size() + 1);
            }
            else {
                printf("No\n");
            }
        }

        if(t) {
            printf("\n");
        }
    }
}

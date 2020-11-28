#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int n;
vector<ii> v;

vector<int> dp, parent;
vector<bool> visited;

void visitLis(int u) {
    if(parent[u] != -1) {
        visitLis(parent[u]);
    }
    visited[u] = true;
}

int findLis() {
    dp = vector<int>(n);
    parent = vector<int>(n);

    for(int i=0; i<n; i++) {
        if(visited[i]) {
            dp[i] = 0;
            continue;
        }

        dp[i] = 1;
        parent[i] = -1;

        for(int j=i-1; j>=0; j--) {
            if(!visited[j] and v[i].first > v[j].first and v[i].second > v[j].second) {
                if(dp[j]+1 > dp[i]) {
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
        }
    }

    int endLis = max_element(dp.begin(), dp.end()) - dp.begin();

    visitLis(endLis);

    return dp[endLis];
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
        sort(v.begin(), v.end());

        int removed = 0, iterations = 0;
        while(removed < n) {
            removed += findLis();
            iterations++;
        }
        printf("%d\n", iterations);
    }
}

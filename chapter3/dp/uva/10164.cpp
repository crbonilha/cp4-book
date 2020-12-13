#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2048;

int n;
vector<int> v;

map<pair<int, pair<int, int> >, bool> dp;
map<pair<int, pair<int, int> >, bool> nstep;
bool solve(int item, int used, int m) {
    if(used == n) {
        return m == 0;
    }
    if(item == n*2-1) {
        return false;
    }

    pair<int, pair<int, int> > key = {item, {used, m}};
    if(dp.find(key) != dp.end()) {
        return dp[key];
    }
    dp[key] = false;

    if(used < n and solve(item+1, used+1, (m+v[item])%n)) {
        nstep[key] = true;
        dp[key] = true;
    }
    else if(solve(item+1, used, m)) {
        nstep[key] = false;
        dp[key] = true;
    }

    return dp[key];
}

int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;

        v = vector<int>(2*n-1);
        for(int i=0; i<2*n-1; i++) {
            scanf("%d", &v[i]);
        }

        dp.clear();
        nstep.clear();
        bool ans = solve(0, 0, 0);

        if(ans) {
            printf("Yes\n");
            pair<int, pair<int, int> > key = {0, {0, 0}};
            int printedCount = 0;
            while(key.first < n*2-1) {
                if(nstep[key]) {
                    printf("%d%c", v[key.first], " \n"[printedCount == n-1]);
                    printedCount++;

                    key.second.first++;
                    key.second.second = (key.second.second+v[key.first])%n;
                }
                key.first++;
            }
        }
        else {
            printf("No\n");
        }
    }
}

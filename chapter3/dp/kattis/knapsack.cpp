#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using vii = vector<ii>;

int n, c;
vii item;

int dp[2000][2001];
bool takeItem[2000][2001];
int solve(int curItem, int curWeight) {
    if(curItem == n) {
        return 0;
    }

    int& ans = dp[curItem][curWeight];
    if(ans != -1) {
        return ans;
    }

    ans = solve(curItem+1, curWeight);

    if(curWeight + item[curItem].second <= c) {
        int candidate = solve(curItem+1, curWeight + item[curItem].second) + item[curItem].first;

        if(candidate > ans) {
            ans = candidate;
            takeItem[curItem][curWeight] = true;
        }
    }
    
    return ans;
}

int main() {
    while(scanf("%d %d", &c, &n) != EOF) {
        item = vii(n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &item[i].first, &item[i].second);
        }

        memset(dp, -1, sizeof(dp));
        memset(takeItem, false, sizeof(takeItem));

        solve(0, 0);

        vector<int> itemsTaken;
        for(int i=0, weight=0; i<n; i++) {
            if(takeItem[i][weight]) {
                itemsTaken.push_back(i);
                weight += item[i].second;
            }
        }
        printf("%d\n", (int)itemsTaken.size());
        for(int i=0; i<(int)itemsTaken.size(); i++) {
            printf("%d%c", itemsTaken[i], " \n"[i == (int)itemsTaken.size()-1]);
        }
    }
}

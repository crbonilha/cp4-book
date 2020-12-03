#include <bits/stdc++.h>
using namespace std;

const int MAX_ITEMS = 1000, MAX_WEIGHT = 2000;

int n;
vector<int> w;

int ans;
bool dp[MAX_ITEMS][MAX_WEIGHT+1];
void solve(int item, int curWeight) {
    if(item == n) {
        if(abs(curWeight-1000) < abs(ans-1000) or
        (abs(curWeight-1000) == abs(ans-1000) and curWeight > 1000)) {
            ans = curWeight;
        }
        return;
    }

    if(dp[item][curWeight]) {
        return;
    }
    dp[item][curWeight] = true;

    solve(item+1, curWeight);
    solve(item+1, min(curWeight+w[item], 2000));
}

int main() {
    scanf("%d", &n);

    w = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &w[i]);
    }

    solve(0, 0);
    printf("%d\n", ans);
}

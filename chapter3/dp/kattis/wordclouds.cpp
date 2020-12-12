#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int INF = 0x3f3f3f3f;
const int MAXW = 5000;

int words, maxW;
ii word[MAXW];

int dp[MAXW];
int solve(int w) {
    if(w == words) {
        return 0;
    }

    int& ans = dp[w];
    if(ans != -1) {
        return ans;
    }
    ans = INF;

    int curWidth = 0, maxHeight = 0;
    for(int i=w; i<words and curWidth+word[i].first <= maxW; i++) {
        curWidth += word[i].first;
        maxHeight = max(maxHeight, word[i].second);
        ans = min(ans, solve(i+1) + maxHeight);
    }
    return ans;
}

int main() {
    scanf("%d %d", &words, &maxW);

    for(int i=0; i<words; i++) {
        scanf("%d %d", &word[i].first, &word[i].second);
    }

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0));
}

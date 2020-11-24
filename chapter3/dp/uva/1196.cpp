#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int n;
vector<ii> blocks;
vector<int> dp;

int main() {
    while(true) {
        scanf("%d", &n);
        if(!n) break;

        blocks = vector<ii>(n+1);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &blocks[i].first, &blocks[i].second);
        }
        blocks[n].first = 101;
        blocks[n].second = 101;
        n++;
        sort(blocks.begin(), blocks.end());

        dp = vector<int>(n);
        for(int i=0; i<n; i++) {
            dp[i] = 0;

            for(int j=i-1; j>=0; j--) {
                if(blocks[i].first >= blocks[j].first and blocks[i].second >= blocks[j].second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        printf("%d\n", dp[n-1]);
    }
    printf("*\n");
}

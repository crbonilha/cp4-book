#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAXN = 30000;
const int MAXH = 100000;

int n;
map<int, vector<ii> > floorAd;

int dp[MAXH*2+1];

int main() {
    int t, tt=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);

        floorAd.clear();

        int maxHeight = 0;
        for(int i=0; i<n; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);

            if(floorAd.find(a+b-1) == floorAd.end()) {
                floorAd[a+b-1] = vector<ii>();
            }
            floorAd[a+b-1].push_back({b, c});

            maxHeight = max(maxHeight, a+b);
        }
        
        for(int i=1; i<=maxHeight; i++) {
            dp[i] = dp[i-1];

            for(ii ad : floorAd[i]) {
                dp[i] = max(dp[i], dp[i-ad.first]+ad.second);
            }
        }
        printf("Case %d: %d\n", tt++, dp[maxHeight]);
    }
}

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int tc() {
    int n;
    scanf("%d", &n);

    vector<ii> items(n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &items[i].first, &items[i].second);
    }

    int answer = 0;

    int people;
    scanf("%d", &people);
    while(people--) {
        int weight;
        scanf("%d", &weight);

        vector<vector<int> > dp(n+1, vector<int>(weight+1));
        for(int i=n; i>=0; i--) {
            for(int j=0; j<=weight; j++) {
                if(i == n) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = max(
                        dp[i+1][j],
                        j >= items[i].second ? dp[i+1][ j-items[i].second ] + items[i].first : 0
                    );
                }
            }
        }
        answer += dp[0][weight];
    }

    return answer;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%d\n", tc());
    }
}

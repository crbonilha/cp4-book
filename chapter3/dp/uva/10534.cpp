#include <bits/stdc++.h>
using namespace std;

const int INC = 0, DEC = 1;

int n;
vector<int> v;
vector<int> lis[2];
vector<int> dp[2];

int main() {
    while(scanf("%d", &n) != EOF) {
        v = vector<int>(n);

        lis[INC].clear();
        lis[DEC].clear();
        dp[INC] = vector<int>(n);
        dp[DEC] = vector<int>(n);

        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        for(int i=0; i<n; i++) {
            int pos = lower_bound(lis[INC].begin(), lis[INC].end(), v[i]) - lis[INC].begin();

            if(pos < (int)lis[INC].size()) {
                lis[INC][pos] = v[i];
            }
            else {
                lis[INC].push_back(v[i]);
            }

            dp[INC][i] = pos+1;
        }

        for(int i=n-1; i>=0; i--) {
            int pos = lower_bound(lis[DEC].begin(), lis[DEC].end(), v[i]) - lis[DEC].begin();

            if(pos < (int)lis[DEC].size()) {
                lis[DEC][pos] = v[i];
            }
            else {
                lis[DEC].push_back(v[i]);
            }

            dp[DEC][i] = pos+1;
        }

        int answer = 1;
        for(int i=0; i<n; i++) {
            answer = max(answer, min(dp[INC][i], dp[DEC][i])*2-1);
        }
        printf("%d\n", answer);
    }
}

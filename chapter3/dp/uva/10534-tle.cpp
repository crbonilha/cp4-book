#include <bits/stdc++.h>
using namespace std;

const int INC = 0, DEC = 1;

int n;
vector<int> v;
vector<int> dp[2];

int main() {
    while(scanf("%d", &n) != EOF) {
        v = vector<int>(n);
        dp[INC] = vector<int>(n);
        dp[DEC] = vector<int>(n);

        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        for(int i=0; i<n; i++) {
            dp[INC][i] = 1;

            for(int j=i-1; j>=0; j--) {
                if(v[i] > v[j]) {
                    dp[INC][i] = max(dp[INC][i], dp[INC][j]+1);
                }
            }
        }

        for(int i=n-1; i>=0; i--) {
            dp[DEC][i] = 1;

            for(int j=i+1; j<n; j++) {
                if(v[i] > v[j]) {
                    dp[DEC][i] = max(dp[DEC][i], dp[DEC][j]+1);
                }
            }
        }

        int answer = 1;
        for(int i=0; i<n; i++) {
            answer = max(answer, min(dp[INC][i], dp[DEC][i])*2-1);
        }
        printf("%d\n", answer);
    }
}

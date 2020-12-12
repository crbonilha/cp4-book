#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

vector<int> squares;
int dp[MAXN+1];

int solve() {
    int n;
    scanf("%d", &n);

    return dp[n];
}

int main() {
    for(int i=1; i*i<=MAXN; i++) {
        squares.push_back(i*i);
    }

    for(int i=1; i<=MAXN; i++) {
        dp[i] = dp[i-1]+1;
        for(int square : squares) {
            if(square > i) {
                continue;
            }

            dp[i] = min(dp[i], dp[i-square]+1);
        }
    }

    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%d\n", solve());
    }
}

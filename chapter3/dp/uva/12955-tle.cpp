#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000, MAXK = 1000;

vector<int> fact;

bool dp[MAXN+1][2];
int solve(int n) {
    for(int i=0; ; i++) {
        int cur = i%2;
        int prev = 1-cur;

        for(int j=0; j<=n; j++) {
            if(i == 0 and j == 0) {
                dp[j][cur] = true;
            }
            else if(i == 0) {
                dp[j][cur] = false;
            }
            else {
                dp[j][cur] = false;
                for(int f : fact) {
                    if(j >= f) {
                        dp[j][cur] = dp[j][cur] or dp[j-f][prev];
                    }
                }
            }
        }

        if(dp[n][cur] == true) {
            return i;
        }
    }
}

int main() {
    int f = 1;
    for(int i=1; f*i < MAXN; i++) {
        f *= i;
        fact.push_back(f);
    }

    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", solve(n));
    }
}

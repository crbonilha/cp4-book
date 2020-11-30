#include <bits/stdc++.h>
using namespace std;

using lli = long long int;

const int MAX_VAL = 7489;

const int coins[] = {1, 5, 10, 25, 50};

lli dp[MAX_VAL+1][6];

void preprocess() {
    for(int i=0; i<=MAX_VAL; i++) {
        for(int j=0; j<6; j++) {
            if(i == 0) {
                dp[i][j] = 1;
            }
            else if(j == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i][j-1];

                if(i-coins[j-1] >= 0) {
                    dp[i][j] += dp[ i-coins[j-1] ][j];
                }
            }
        }
    }
}

int main() {
    preprocess();

    int n;
    while(scanf("%d", &n) != EOF) {
        printf("%d\n", dp[n][5]);
    }
}

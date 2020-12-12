#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;

int dp[MAXN+1];

int main() {
    dp[0] = 1;
    for(int i=1; i<=MAXN; i++) {
        dp[i] = dp[int(floor(i - sqrt(double(i))))]
               + dp[(int)floor(log((double)i))]
               + dp[(int)floor(i * sin((double)i) * sin((double)i))];
        dp[i] %= MAXN;
    }

    while(true) {
        int n;
        scanf("%d", &n);
        if(n == -1) break;

        printf("%d\n", dp[n]);
    }
}

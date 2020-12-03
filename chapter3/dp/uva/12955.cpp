#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000, MAXK = 50;
const int OK = 1, NOTOK = 2;

vector<int> fact;

int dp[MAXN+1][MAXK];
int solve(int n, int kRem) {
    if(kRem == 0) {
        return n == 0 ? OK : NOTOK;
    }

    int& ans = dp[n][kRem];
    if(ans != -1) {
        return ans;
    }

    ans = NOTOK;
    for(int f : fact) {
        if(n >= f) {
            int candidate = solve(n-f, kRem-1);

            if(candidate == OK) {
                return ans = OK;
            }
        }
    }
    return ans;
}

int main() {
    int f = 1;
    for(int i=1; f*i <= MAXN; i++) {
        f *= i;
        fact.push_back(f);
    }

    memset(dp, -1, sizeof(dp));

    int n;
    while(scanf("%d", &n) != EOF) {
        for(int i=1; i<MAXK; i++) {
            if(solve(n, i) == OK) {
                printf("%d\n", i);
                break;
            }
        }
    }
}

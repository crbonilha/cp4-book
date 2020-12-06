#include <bits/stdc++.h>
using namespace std;

const int OK = 1, NOTOK = 2;
const int MAXN = 10000, MAXK = 100;

int n, k;
vector<int> seq;

int dp[MAXN][MAXK];
int solve(int el, int sum) {
    if(el == n) {
        return sum == 0 ? OK : NOTOK;
    }

    int& ans = dp[el][sum];
    if(ans != -1) {
        return ans;
    }

    ans = NOTOK;
    if(solve(el+1, (sum + k + (seq[el]%k)) % k) == OK) {
        ans = OK;
    }
    else if(solve(el+1, (sum + k - (seq[el]%k)) % k) == OK) {
        ans = OK;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);

        seq = vector<int>(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &seq[i]);
        }

        memset(dp, -1, sizeof(dp));
        printf("%s\n", solve(0, 0) == OK ? "Divisible" : "Not divisible");
    }
}

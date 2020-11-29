#include <bits/stdc++.h>
using namespace std;

const int MAX_PRIME = 1120;
const int MAX_K = 14;

bool isPrime(int u) {
    if(u == 2) return true;
    if(u % 2 == 0) return false;

    for(int i=3; i<=int(ceil(sqrt(u))); i+=2) {
        if(u % i == 0) {
            return false;
        }
    }

    return true;
}

vector<int> primes;
void populatePrimes() {
    for(int i=2; i<=MAX_PRIME; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }
}

int dp[200][MAX_PRIME+1][MAX_K+1];
int solve(int n, int k) {
    for(int i=0; i<=(int)primes.size(); i++) {
        for(int j=0; j<=n; j++) {
            for(int m=0; m<=k; m++) {
                if(j == 0 and m == 0) {
                    dp[i][j][m] = 1;
                }
                else if(i == 0 or j == 0 or m == 0) {
                    dp[i][j][m] = 0;
                }
                else {
                    dp[i][j][m] = dp[i-1][j][m];
                    if(j >= primes[i-1]) {
                        dp[i][j][m] += dp[i-1][ j-primes[i-1] ][m-1];
                    }
                }
            }
        }
    }
    return dp[(int)primes.size()][n][k];
}

int main() {
    populatePrimes();

    while(true) {
        int n, k;
        scanf("%d %d", &n, &k);
        if(n == 0 and k == 0) break;

        printf("%d\n", solve(n, k));
    }
}

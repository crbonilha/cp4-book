#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> coins;

int dp[2000001];
int greedy[2000001];
bool isCanonical() {
    int counterExampleLimit = coins[n-2] + coins[n-1];

    for(int i=1; i<=counterExampleLimit; i++) {
        dp[i] = INF;

        for(int j=0; j<n; j++) {
            if(i >= coins[j]) {
                dp[i] = min(dp[i], dp[ i-coins[j] ]+1);
                greedy[i] = greedy[ i-coins[j] ]+1;
            }
            else {
                break;
            }
        }

        if(greedy[i] > dp[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    scanf("%d", &n);

    coins = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("%s\n", isCanonical() ? "canonical" : "non-canonical");
}

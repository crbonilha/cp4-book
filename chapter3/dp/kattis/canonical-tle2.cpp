#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> coins;

int greedy(int val) {
    int answer = 0;
    for(int i=(int)coins.size()-1; i>=0; i--) {
        int amount = val/coins[i];
        answer += amount;
        val -= amount*coins[i];
    }
    return answer;
}

int dp[101][2000000];
bool hasCounterExample() {
    int counterExampleLimit = coins[n-2] + coins[n-1];

    for(int j=0; j<=counterExampleLimit; j++) {
        for(int i=0; i<=n; i++) {
            if(j == 0) {
                dp[i][j] = 0;
            }
            else if(i == 0) {
                dp[i][j] = INF;
            }
            else {
                dp[i][j] = dp[i-1][j];

                if(j >= coins[i-1]) {
                    dp[i][j] = min(dp[i][j], dp[i][ j-coins[i-1] ]+1);
                }
            }
        }

        if(greedy(j) > dp[n][j]) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    coins = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("%s\n", hasCounterExample() ? "non-canonical" : "canonical");
}

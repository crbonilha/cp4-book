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

int dp[2][2000000];
bool hasCounterExample() {
    int counterExampleLimit = coins[n-2] + coins[n-1];

    for(int i=0; i<=n; i++) {
        int aux = i%2;
        int prev = 1-aux;

        for(int j=0; j<=counterExampleLimit; j++) {
            if(j == 0) {
                dp[aux][j] = 0;
            }
            else if(i == 0) {
                dp[aux][j] = INF;
            }
            else {
                dp[aux][j] = dp[prev][j];

                if(j >= coins[i-1]) {
                    dp[aux][j] = min(dp[aux][j], dp[aux][ j-coins[i-1] ]+1);
                }
            }
        }
    }

    for(int i=2; i<=counterExampleLimit; i++) {
        if(greedy(i) > dp[n%2][i]) {
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

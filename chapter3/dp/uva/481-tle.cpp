#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;

vector<int> v;
vector<int> previous, dp;

int main() {
    int aux;
    while(scanf("%d", &aux) != EOF) {
        v.push_back(aux);
    }
    v.push_back(INF);

    int n = (int)v.size();

    previous = vector<int>(n);
    dp = vector<int>(n);

    for(int i=0; i<n; i++) {
        dp[i] = 0;
        previous[i] = -1;

        for(int j=i-1; j>=0; j--) {
            if(v[j] < v[i] and dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                previous[i] = j;
            }
        }
    }

    vector<int> sequence;
    int current = previous[n-1];
    do {
        sequence.push_back(v[current]);
        current = previous[current];
    } while(current != -1);

    reverse(sequence.begin(), sequence.end());
    printf("%d\n-\n", (int)sequence.size());
    for(int aux : sequence) {
        printf("%d\n", aux);
    }
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

vector<int> dp;
vector<int> prevIndex;

void printLis(int u) {
    if(prevIndex[u] != -1) {
        printLis(prevIndex[u]);
    }
    printf(" %d", v[u]);
}

int main() {
    while(true) {
        scanf("%d", &n);
        if(!n) break;

        v = vector<int>(n);
        dp = vector<int>(n);
        prevIndex = vector<int>(n);

        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        for(int i=0; i<n; i++) {
            dp[i] = 1;
            prevIndex[i] = -1;

            for(int j=i-1; j>=0; j--) {
                if(v[i] > v[j]) {
                    if(dp[j]+1 > dp[i]) {
                        dp[i] = dp[j]+1;
                        prevIndex[i] = j;
                    }
                    else if(dp[j]+1 == dp[i] and v[j] < v[ prevIndex[i] ]) {
                        prevIndex[i] = j;
                    }
                }
            }
        }

        int lisEnd = 0;
        for(int i=1; i<n; i++) {
            if(dp[i] > dp[lisEnd] or
            (dp[i] == dp[lisEnd] and v[i] < v[lisEnd])) {
                lisEnd = i;
            }
        }

        printf("%d", dp[lisEnd]);
        printLis(lisEnd);
        printf("\n");
    }
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> item;
vector<int> order;

int dp[101][30001];
int prevStep[101][30001];
void buildKnapsack(int highestOrder) {
    for(int i=0; i<=(int)item.size(); i++) {
        for(int j=0; j<=highestOrder; j++) {
            if(i == 0 and j == 0) {
                dp[i][j] = 1;
            }
            else if(i == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i-1][j];

                for(int k=1; j-k*item[i-1]>=0; k++) {
                    if(dp[i-1][ j-k*item[i-1] ]) {
                        prevStep[i][j] = k;
                        dp[i][j] = min(2, dp[i][j] + dp[i-1][ j-k*item[i-1] ]);
                    }
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);

    item = vector<int>(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &item[i]);
    }

    int m;
    scanf("%d", &m);

    order = vector<int>(m);
    for(int i=0; i<m; i++) {
        scanf("%d", &order[i]);
    }

    int highestOrder = *max_element(order.begin(), order.end());

    buildKnapsack(highestOrder);

    for(int order : order) {
        if(dp[(int)item.size()][order] == 0) {
            printf("Impossible\n");
        }
        else if(dp[(int)item.size()][order] > 1) {
            printf("Ambiguous\n");
        }
        else {
            vector<int> ans;
            for(int i=(int)item.size(), weight=order; i>0; i--) {
                for(int j=0; j<prevStep[i][weight]; j++) {
                    ans.push_back(i);
                }
                weight -= prevStep[i][weight]*item[i-1];
            }
            for(int i=0; i<(int)ans.size(); i++) {
                printf("%d%c", ans[(int)ans.size()-i-1], " \n"[i == (int)ans.size()-1]);
            }
        }
    }
}

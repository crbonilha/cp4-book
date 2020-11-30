#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> item;

int dp[100][30001];
int takeItem[100][30001];
int solve(int curItem, int curCost, int budget) {
    if(curItem == n) {
        return curCost == budget;
    }

    int& ans = dp[curItem][curCost];
    if(ans != -1) {
        return ans;
    }

    ans = solve(curItem+1, curCost, budget);
    for(int qty=1; curCost+qty*item[curItem] <= budget; qty++) {
        int candidate = solve(curItem+1, curCost+qty*item[curItem], budget);
        if(candidate) {
            ans += candidate;
            takeItem[curItem][curCost] = qty;
        }
    }

    return ans;
}

void knapsack(int budget) {
    memset(dp, -1, sizeof(dp));
    memset(takeItem, 0, sizeof(takeItem));

    int possibilities = solve(0, 0, budget);

    if(!possibilities) {
        printf("Impossible\n");
    }
    else if(possibilities > 1) {
        printf("Ambiguous\n");
    }
    else {
        vector<int> order;
        for(int i=0, weight=0; i<n; i++) {
            for(int j=0; j<takeItem[i][weight]; j++) {
                order.push_back(i+1);
            }
            weight += takeItem[i][weight]*item[i];
        }
        for(int i=0; i<(int)order.size(); i++) {
            printf("%d%c", order[i], " \n"[i == (int)order.size()-1]);
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
    while(m--) {
        int budget;
        scanf("%d", &budget);

        knapsack(budget);
    }
}

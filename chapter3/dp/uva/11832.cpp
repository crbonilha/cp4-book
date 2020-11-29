#include <bits/stdc++.h>
using namespace std;

const int MAX_PAGES = 40;
const int MAX_FLOW = 80000;
const int CASH_OFFSET = 40000;

int pages, cashFlow;
vector<int> transaction;

int possibleSign[2][MAX_PAGES];
int dp[MAX_PAGES][MAX_FLOW+1];
int solve(int page, int cash) {
    if(page == pages) {
        return cash == cashFlow ? 1 : 0;
    }

    int& ans = dp[page][CASH_OFFSET + cash];
    if(ans != -1) {
        return ans;
    }

    ans = 0;

    if(solve(page+1, cash+transaction[page])) {
        possibleSign[1][page]++;
        ans = 1;
    }

    if(solve(page+1, cash-transaction[page])) {
        possibleSign[0][page]++;
        ans = 1;
    }

    return ans;
}

int main() {
    while(true) {
        scanf("%d %d", &pages, &cashFlow);
        if(pages == 0) break;

        transaction = vector<int>(pages);
        for(int i=0; i<pages; i++) {
            scanf("%d", &transaction[i]);

            possibleSign[0][i] = possibleSign[1][i] = 0;
        }

        memset(dp, -1, sizeof(dp));
        if(solve(0, 0)) {
            for(int i=0; i<pages; i++) {
                printf("%c", possibleSign[0][i] and possibleSign[1][i] ? '?' : (possibleSign[0][i] ? '-' : '+'));
            }
            printf("\n");
        }
        else {
            printf("*\n");
        }
    }
}

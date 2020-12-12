#include <bits/stdc++.h>
using namespace std;

const int OK = 1, NOTOK = 2;
const int MAXL = 40, MAXW = 1000;

int l, w;

int dp[MAXL][MAXW+1];
int solve(int pos, int curW) {
    if(pos == l) {
        return curW == w ? OK : NOTOK;
    }

    int& ans = dp[pos][curW];
    if(ans != 0) {
        return ans;
    }

    for(int i=1; i<=26; i++) {
        if(curW+i <= w and solve(pos+1, curW+i) == OK) {
            printf("%c", 'a'+(i-1));
            return ans = OK;
        }
    }
    return ans = NOTOK;
}

int main() {
    scanf("%d %d", &l, &w);

    if(solve(0, 0) == NOTOK) {
        printf("impossible\n");
    }
    else {
        printf("\n");
    }
}

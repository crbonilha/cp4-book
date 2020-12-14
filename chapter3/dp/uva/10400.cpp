#include <bits/stdc++.h>
using namespace std;

const int OK = 1, NOTOK = 2;
const int MAXN = 1e2;
const int OFFSET = 32000;
const int MAXVAL = OFFSET*2+1;

int n, target;
int val[MAXN];

int dp[MAXN][MAXVAL];
char nstep[MAXN][MAXVAL];
int solve(int v, int sum) {
    if(v == n) {
        return sum == target ? OK : NOTOK;
    }

    int& ans = dp[v][OFFSET+sum];
    if(ans != -1) {
        return ans;
    }

    if(-OFFSET <= sum+val[v] and sum+val[v] <= OFFSET) {
        if(solve(v+1, sum+val[v]) == OK) {
            nstep[v][OFFSET+sum] = '+';
            return ans = OK;
        }
    }
    if(-OFFSET <= sum-val[v] and sum-val[v] <= OFFSET) {
        if(solve(v+1, sum-val[v]) == OK) {
            nstep[v][OFFSET+sum] = '-';
            return ans = OK;
        }
    }
    if(-OFFSET <= sum*val[v] and sum*val[v] <= OFFSET) {
        if(solve(v+1, sum*val[v]) == OK) {
            nstep[v][OFFSET+sum] = '*';
            return ans = OK;
        }
    }
    if(val[v] != 0 and sum%val[v] == 0 and -OFFSET <= sum/val[v] and sum/val[v] <= OFFSET) {
        if(solve(v+1, sum/val[v]) == OK) {
            nstep[v][OFFSET+sum] = '/';
            return ans = OK;
        }
    }

    return ans = NOTOK;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &val[i]);
        }
        scanf("%d", &target);

        memset(dp, -1, sizeof(dp));
        if(solve(1, val[0]) == OK) {
            printf("%d", val[0]);
            for(int i=1, sum=val[0]; i<n; i++) {
                printf("%c%d", nstep[i][OFFSET+sum], val[i]);

                if(nstep[i][OFFSET+sum] == '+') {
                    sum += val[i];
                }
                else if(nstep[i][OFFSET+sum] == '-') {
                    sum -= val[i];
                }
                else if(nstep[i][OFFSET+sum] == '*') {
                    sum *= val[i];
                }
                else {
                    sum /= val[i];
                }
            }
            printf("=%d\n", target);
        }
        else {
            printf("NO EXPRESSION\n");
        }
    }
}

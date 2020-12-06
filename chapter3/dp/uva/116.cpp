#include <bits/stdc++.h>
using namespace std;

const int MAXROWS = 10, MAXCOLS = 100;

int rows, cols;
int mat[MAXROWS][MAXCOLS];

bool visi[MAXROWS][MAXCOLS];
int dp[MAXROWS][MAXCOLS];
int step[MAXROWS][MAXCOLS];
int solve(int row, int col) {
    if(col == cols) {
        return 0;
    }

    int& ans = dp[row][col];
    if(visi[row][col]) {
        return ans;
    }
    visi[row][col] = true;

    step[row][col] = row;
    ans = solve(row, col+1);

    for(int i=-1; i<=1; i+=2) {
        int nextRow = (row+i+rows)%rows;

        int candidate = solve(nextRow, col+1);

        if(candidate < ans) {
            step[row][col] = nextRow;
            ans = candidate;
        }
        else if(candidate == ans) {
            step[row][col] = min(step[row][col], nextRow);
        }
    }

    return ans = ans + mat[row][col];
}

int main() {
    while(scanf("%d %d", &rows, &cols) != EOF) {
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                scanf("%d", &mat[i][j]);
            }
        }

        memset(visi, false, sizeof(visi));

        int startRow = 0;
        solve(startRow, 0);
        for(int i=1; i<rows; i++) {
            if(solve(i, 0) < solve(startRow, 0)) {
                startRow = i;
            }
        }
        for(int i=0, row=startRow; i<cols; i++) {
            printf("%d%c", row+1, " \n"[i == cols-1]);
            row = step[row][i];
        }
        printf("%d\n", solve(startRow, 0));
    }
}

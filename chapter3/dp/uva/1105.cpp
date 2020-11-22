#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAX_DIM = 2001;

int sum[MAX_DIM][MAX_DIM];

ii getCoord(ii gridSize, ii prevCoord) {
    return {
        prevCoord.first + prevCoord.second,
        prevCoord.second - prevCoord.first + gridSize.first
    };
}

int main() {
    int rows, cols, n, q, tt = 1;
    while(true) {
        scanf("%d %d %d %d", &rows, &cols, &n, &q);
        if(rows == 0) break;

        int diagonals = rows+cols;

        printf("Case %d:\n", tt++);

        memset(sum, 0, sizeof(sum));

        for(int i=0; i<n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;

            ii coord = getCoord({rows, cols}, {x, y});

            sum[coord.first][coord.second] = 1;
        }

        for(int i=0; i<diagonals; i++) {
            for(int j=0; j<diagonals; j++) {
                if(i-1 >= 0) sum[i][j] += sum[i-1][j];
                if(j-1 >= 0) sum[i][j] += sum[i][j-1];
                if(i-1 >= 0 and j-1 >= 0) sum[i][j] -= sum[i-1][j-1];
            }
        }

        while(q--) {
            int m;
            scanf("%d", &m);

            int cm = m*2+1;

            pair<int, ii> answer = {0, {1, 1}};
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    ii coord = getCoord({rows, cols}, {i, j});

                    // inclusive
                    ii coordUpperRight = {
                        min(diagonals-1, coord.first+m),
                        min(diagonals-1, coord.second+m)
                    };
                    // exclusive
                    ii coordLowerLeft = {
                        coord.first-m-1,
                        coord.second-m-1
                    };

                    int candidate = sum[coordUpperRight.first][coordUpperRight.second];
                    if(coordLowerLeft.first >= 0)
                        candidate -= sum[coordLowerLeft.first][coordUpperRight.second];
                    if(coordLowerLeft.second >= 0)
                        candidate -= sum[coordUpperRight.first][coordLowerLeft.second];
                    if(coordLowerLeft.first >= 0 and coordLowerLeft.second >= 0)
                        candidate += sum[coordLowerLeft.first][coordLowerLeft.second];

                    if(candidate > answer.first) {
                        answer = {candidate, {i, j}};
                    }
                    else if(candidate == answer.first and
                    (j < answer.second.second or (j == answer.second.second and i < answer.second.first))) {
                        answer.second = {i, j};
                    }
                }
            }
            printf("%d (%d,%d)\n", answer.first, answer.second.first+1, answer.second.second+1);
        }
    }
}

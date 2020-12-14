#include <bits/stdc++.h>
using namespace std;

using ii = pair<double, double>;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000;

int n;
double width;
ii book[MAXN]; // height, width

double dp[MAXN];
double solve(int b) {
    if(b == n) {
        return 0;
    }

    double& ans = dp[b];
    if(ans != -1) {
        return ans;
    }
    ans = INF;

    double bookWidths = 0, maxHeight = 0;
    for(int i=b; i<n; i++) {
        bookWidths += book[i].second;
        maxHeight = max(maxHeight, book[i].first);

        if(bookWidths-width > 1e-9) {
            break;
        }

        ans = min(ans, solve(i+1) + maxHeight);
    }
    return ans;
}

int main() {
    while(true) {
        scanf("%d %lf", &n, &width);
        if(n == 0) break;

        for(int i=0; i<n; i++) {
            scanf("%lf %lf", &book[i].first, &book[i].second);
        }

        for(int i=0; i<n; i++) {
            dp[i] = -1;
        }
        printf("%.4lf\n", solve(0));
    }
}

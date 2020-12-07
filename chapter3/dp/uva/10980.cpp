#include <bits/stdc++.h>
using namespace std;

vector<int> getQueries() {
    char s[512];
    gets(s);

    vector<int> ans;
    int aux = 0;

    int n = strlen(s);
    for(int i=0; i<=n; i++) {
        if(i == n or s[i] == ' ') {
            if(aux) {
                ans.push_back(aux);
            }
            aux = 0;
        }
        else {
            aux *= 10;
            aux += s[i]-'0';
        }
    }
    return ans;
}

int main() {
    double aux;
    int items, tt=1;
    while(scanf("%lf %d ", &aux, &items) != EOF) {
        items++;
        vector<pair<int, double> > item(items);
        item[0] = {1, aux};

        for(int i=1; i<items; i++) {
            scanf("%d %lf ", &item[i].first, &item[i].second);
        }

        vector<double> dp(200);
        dp[0] = 0;

        for(int i=1; i<200; i++) {
            dp[i] = item[0].second * i;

            for(int j=1; j<items; j++) {
                dp[i] = min(dp[i], dp[max(0, i-item[j].first)] + item[j].second);
            }
        }

        printf("Case %d:\n", tt++);
        for(int query : getQueries()) {
            printf("Buy %d for $%.2lf\n", query, dp[query]);
        }
    }
}

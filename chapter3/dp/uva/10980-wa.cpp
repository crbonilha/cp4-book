#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_ITEMS = 21, MAX_QTY = 100;

int n;
vector<pair<int, double> > items; // qty, price

double dp[MAX_ITEMS][MAX_QTY*2+1];
bool visi[MAX_ITEMS][MAX_QTY*2+1];
double solve(int item, int qty, int goal) {
    if(item == n) {
        return qty >= goal ? 0 : INF;
    }

    double& ans = dp[item][qty];
    if(visi[item][qty]) {
        return ans;
    }
    visi[item][qty] = true;

    ans = solve(item+1, qty, goal);
    for(int i=1; qty+i*items[item].first<=goal*2; i++) {
        ans = min(ans, solve(item+1, qty+i*items[item].first, goal)+i*items[item].second);
    }
    return ans;
}

vector<int> getQueries() {
    char s[512];
    gets(s);

    vector<int> ans;

    int n = strlen(s);
    int aux = 0;
    for(int i=0; i<=n; i++) {
        if(i == n or s[i] == ' ') {
            if(aux) {
                ans.push_back(aux);
                aux = 0;
            }
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
    int tt = 1;
    while(scanf("%lf %d ", &aux, &n) != EOF) {
        n++;
        items = vector<pair<int, double> >(n);
        items[0] = {1, aux};
        for(int i=1; i<n; i++) {
            scanf("%d %lf ", &items[i].first, &items[i].second);
        }

        printf("Case %d:\n", tt++);
        vector<int> queries = getQueries();
        for(int query : queries) {
            memset(visi, false, sizeof(visi));
            printf("Buy %d for $%.2lf\n", query, solve(0, 0, query));
        }
    }
}

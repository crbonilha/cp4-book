#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

vector<int> squares;

int solve() {
    int n;
    scanf("%d", &n);

    int ans = 0;
    for(int i=squares.size()-1; i>=0; i--) {
        if(squares[i] > n) {
            continue;
        }

        int uses = n/squares[i];
        n -= uses * squares[i];
        ans += uses;
    }
    return ans;
}

int main() {
    for(int i=1; i*i<=MAXN; i++) {
        squares.push_back(i*i);
    }

    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%d\n", solve());
    }
}

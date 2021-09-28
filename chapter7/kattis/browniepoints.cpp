#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 2e4;

struct point {
    int x, y;
};

int n;
point p[MAXN];

int main() {
    while(true) {
        scanf("%d", &n);
        if(!n) {
            break;
        }

        for(int i=0; i<n; i++) {
            scanf("%d %d", &p[i].x, &p[i].y);
        }

        point mid;
        mid.x = p[n/2].x;
        mid.y = p[n/2].y;

        int stan = 0, ollie = 0;
        for(int i=0; i<n; i++) {
            if(p[i].x > mid.x and p[i].y > mid.y) {
                stan++;
            }
            else if(p[i].x < mid.x and p[i].y < mid.y) {
                stan++;
            }
            else if(p[i].x > mid.x and p[i].y < mid.y) {
                ollie++;
            }
            else if(p[i].x < mid.x and p[i].y > mid.y) {
                ollie++;
            }
        }
        printf("%d %d\n", stan, ollie);
    }
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5;

struct point {
    int x, y;
    point() { x = y = 0; }
    point(int xx, int yy) : x(xx), y(yy) {}
    void rotate() {
        int nx = y, ny = -x;
        x = nx;
        y = ny;
    }
    bool operator < (point other) const {
        if(x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int n;
point pa[MAXN], pb[MAXN];

bool match() {
    sort(pa, pa+n);

    ii offset = {
        pb[0].x - pa[0].x,
        pb[0].y - pa[0].y
    };
    for(int i=0; i<n; i++) {
        if(pa[i].x + offset.first != pb[i].x or
        pa[i].y + offset.second != pb[i].y) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d %d", &pa[i].x, &pa[i].y);
        }
        for(int i=0; i<n; i++) {
            scanf("%d %d", &pb[i].x, &pb[i].y);
        }

        sort(pb, pb+n);

        bool valid = false;
        for(int i=0; i<4; i++) {
            if(match()) {
                valid = true;
                break;
            }
            
            for(int j=0; j<n; j++) {
                pa[j].rotate();
            }
        }
        printf("%s\n", valid ? "MATCHED" : "NOT MATCHED");
    }
}

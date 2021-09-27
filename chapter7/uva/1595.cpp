#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1000;

struct point {
    int x, y;
    point() { x = 0, y = 0; }
    point(int xx, int yy) : x(xx), y(yy) {}
    bool operator < (point other) const {
        if(x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
};

int n;
point p[MAXN];

bool solve() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &p[i].x, &p[i].y);
    }

    int leastX = 1e9, mostX = -1e9;
    set<point> s;
    for(int i=0; i<n; i++) {
        leastX = min(leastX, p[i].x);
        mostX = max(mostX, p[i].x);

        s.insert(p[i]);
    }
    int mid = (mostX + leastX) / 2;
    bool rounded = (mostX + leastX) % 2;

    for(point p: s) {
        if(!rounded and p.x == mid) {
            continue;
        }

        int counterX;
        if(rounded) {
            if(p.x <= mid) {
                counterX = mid + (mid - p.x) + 1;
            }
            else {
                return false;
            }
        }
        else {
            if(p.x < mid) {
                counterX = mid + (mid - p.x);
            }
            else {
                return false;
            }
        }

        set<point>::iterator it = s.find(point(counterX, p.y));
        if(it == s.end()) {
            return false;
        }
        s.erase(it);
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        printf("%s\n", solve() ? "YES" : "NO");
    }
}

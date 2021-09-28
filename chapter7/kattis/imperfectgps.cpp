#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 100;

struct point {
    double x, y;
    point() { x = y = 0; }
    point(double xx, double yy) {
        x = xx;
        y = yy;
    }
};

int n, k;
vector<point> p;
int t[MAXN];

double getDist(vector<point>& p) {
    double ans = 0;
    for(int i=1; i<p.size(); i++) {
        ans += hypot(p[i].x - p[i-1].x, p[i].y - p[i-1].y);
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        point aux;
        scanf("%lf %lf %d", &aux.x, &aux.y, &t[i]);
        p.push_back(aux);
    }

    vector<point> gps = {p[0]};
    int curTime = 0;
    for(int i=1; i<n; i++) {
        while(curTime+k <= t[i]) {
            curTime += k;

            double diff = t[i] - t[i-1];
            double curDiff = curTime - t[i-1];
            double xDiff = p[i].x - p[i-1].x;
            double yDiff = p[i].y - p[i-1].y;

            gps.push_back({
                p[i-1].x + (curDiff/diff) * xDiff,
                p[i-1].y + (curDiff/diff) * yDiff
            });
        }
    }
    gps.push_back(p[n-1]);

    double total = getDist(p);
    double gpsTotal = getDist(gps);
    printf("%.10lf\n", 100.0 - (gpsTotal / total) * 100.0);
}

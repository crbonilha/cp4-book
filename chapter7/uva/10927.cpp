#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5;

struct point {
    int x, y;
    int g;
    point() { x = y = g = 0; }
    point(int _x, int _y) : x(_x), y(_y) {
        g = __gcd(x, y);
    }
    bool operator < (point other) const {
        if(x == other.x) {
            return y < other.y;
        }
        return x < other.x;
    }
    ii getSlope() const {
        return {y/g, x/g};
    }
    double getSlopeDouble() const {
        ii slope = getSlope();
        return double(slope.first) / double(slope.second);
    }
};
using pi = pair<point, int>;

int n;
pi p[MAXN];

int main() {
    int t = 0;
    while(true) {
        scanf("%d", &n);
        if(!n) {
            break;
        }
        t++;

        for(int i=0; i<n; i++) {
            scanf("%d %d %d", &p[i].first.x, &p[i].first.y, &p[i].second);
            p[i].first.g = __gcd(p[i].first.x, p[i].first.y);
        }

        vector<pi> horLeft, horRight, ver, normal;
        for(int i=0; i<n; i++) {
            if(p[i].first.y == 0) {
                if(p[i].first.x < 0) {
                    horLeft.push_back(p[i]);
                }
                else {
                    horRight.push_back(p[i]);
                }
            }
            else if(p[i].first.x == 0) {
                ver.push_back(p[i]);
            }
            else {
                normal.push_back(p[i]);
            }
        }

        vector<point> ans;

        sort(horLeft.begin(), horLeft.end(), [&](const pi a, const pi b) {
            return a.first.x > b.first.x;
        });
        int highest = -1;
        for(int i=0; i<horLeft.size(); i++) {
            if(horLeft[i].second <= highest) {
                ans.push_back(horLeft[i].first);
            }
            highest = max(highest, horLeft[i].second);
        }

        sort(horRight.begin(), horRight.end(), [&](const pi a, const pi b) {
            return a.first.x < b.first.x;
        });
        highest = -1;
        for(int i=0; i<horRight.size(); i++) {
            if(horRight[i].second <= highest) {
                ans.push_back(horRight[i].first);
            }
            highest = max(highest, horRight[i].second);
        }

        sort(ver.begin(), ver.end(), [&](const pi a, const pi b) {
            return a.first.y < b.first.y;
        });
        highest = -1;
        for(int i=0; i<ver.size(); i++) {
            if(ver[i].second <= highest) {
                ans.push_back(ver[i].first);
            }
            highest = max(highest, ver[i].second);
        }

        sort(normal.begin(), normal.end(), [&](const pi a, const pi b) {
            if(a.first.getSlope() == b.first.getSlope()) {
                return hypot(a.first.x, a.first.y) < hypot(b.first.x, b.first.y);
            }
            return a.first.getSlopeDouble() < b.first.getSlopeDouble();
        });
        ii lastSlope = {-1, -1};
        highest = -1;
        for(int i=0; i<normal.size(); i++) {
            if(normal[i].first.getSlope() == lastSlope) {
                if(normal[i].second <= highest) {
                    ans.push_back(normal[i].first);
                }
                highest = max(highest, normal[i].second);
            }
            else {
                lastSlope = normal[i].first.getSlope();
                highest = normal[i].second;
            }
        }

        printf("Data set %d:\n", t);
        if(ans.empty()) {
            printf("All the lights are visible.\n");
        }
        else {
            sort(ans.begin(), ans.end());
            printf("Some lights are not visible:\n");
            for(int i=0; i<ans.size(); i++) {
                printf("x = %d, y = %d%c\n", ans[i].x, ans[i].y, ";."[i+1 == ans.size()]);
            }
        }
    }
}

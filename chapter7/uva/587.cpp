#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 200;
const double DIAG = 0.70710678;
const pair<double, double> DIR[8] = {
    {0, 1}, {DIAG, DIAG}, {1, 0}, {DIAG, -DIAG},
    {0, -1}, {-DIAG, -DIAG}, {-1, 0}, {-DIAG, DIAG}
};

char s[MAXN+10];
int n;

vector<ii> getDirections() {
    vector<ii> ans;
    int len = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == ',' or s[i] == '.') {
            if(s[i-1] == 'N') {
                ans.push_back({len, 0});
            }
            else if(s[i-1] == 'E') {
                if(s[i-2] == 'N') {
                    ans.push_back({len, 1});
                }
                else if(s[i-2] == 'S') {
                    ans.push_back({len, 3});
                }
                else {
                    ans.push_back({len, 2});
                }
            }
            else if(s[i-1] == 'S') {
                ans.push_back({len, 4});
            }
            else if(s[i-1] == 'W') {
                if(s[i-2] == 'N') {
                    ans.push_back({len, 7});
                }
                else if(s[i-2] == 'S') {
                    ans.push_back({len, 5});
                }
                else {
                    ans.push_back({len, 6});
                }
            }
            len = 0;
        }
        else if(s[i] >= '0' and s[i] <= '9') {
            len *= 10;
            len += s[i] - '0';
        }
    }
    return ans;
}

struct point {
    double x, y;
    point() { x = 0; y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

int main() {
    int t = 0;
    while(true) {
        t++;
        scanf("%s", s);
        n = strlen(s);

        if(s[0] == 'E') {
            break;
        }

        vector<ii> directions = getDirections();
        point pos;
        for(ii dir: directions) {
            pos.x += dir.first * DIR[dir.second].first;
            pos.y += dir.first * DIR[dir.second].second;
        }
        printf("Map #%d\n", t);
        printf("The treasure is located at (%.3lf,%.3lf).\n", pos.x, pos.y);
        printf("The distance to the treasure is %.3lf.\n", hypot(pos.x, pos.y));
        printf("\n");
    }
}

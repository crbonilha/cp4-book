#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

const int MAXN = 1e5;
const double EPS = 1e-9;

struct point {
    double x, y;
};

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        point book;
        scanf("%lf %lf", &book.x, &book.y);

        int n;
        scanf("%d", &n);

        bool valid = false;
        while(n--) {
            point candle;
            scanf("%lf %lf", &candle.x, &candle.y);

            if(fabs(hypot(book.x - candle.x, book.y - candle.y)) <= 8.0) {
                valid = true;
            }
        }
        printf("%s\n", valid ? "light a candle" : "curse the darkness");
    }
}

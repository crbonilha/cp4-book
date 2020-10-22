#include <bits/stdc++.h>
using namespace std;

// 1000000000000000000
// 1414213561

using ll = long long;

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        ll warriors;
        scanf("%lld", &warriors);

        ll answer = 0;

        ll ini = 0, mid, fim = sqrt(warriors)*2;
        while(ini < fim) {
            mid = (ini+fim)/2;

            if(mid*(mid+1)/2 <= warriors) {
                answer = max(answer, mid);
                ini = mid+1;
            }
            else {
                fim = mid;
            }
        }

        printf("%lld\n", answer);
    }
}
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

        ll answer = ceil(sqrt(warriors*2));
        while(answer*(answer+1)/2 > warriors) {
            answer--;
        }

        printf("%lld\n", answer);
    }
}
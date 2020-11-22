#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(true) {
        scanf("%d", &n);
        if(!n) break;

        vector<int> v(n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        int answer = 0;
        int current = 0;
        for(int bet : v) {
            current += bet;
            current = max(0, current);
            answer = max(answer, current);
        }
        if(answer == 0) {
            printf("Losing streak.\n");
        }
        else {
            printf("The maximum winning streak is %d.\n", answer);
        }
    }
}

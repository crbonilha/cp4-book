#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<int, int>;

const int MAX_S = 20;

lli sum[MAX_S][MAX_S][MAX_S];

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                for(int k=0; k<c; k++) {
                    scanf("%lld", &sum[i][j][k]);
                }
            }
        }

        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                for(int k=0; k<c; k++) {
                    if(i-1 >= 0) sum[i][j][k] += sum[i-1][j][k];
                    if(j-1 >= 0) sum[i][j][k] += sum[i][j-1][k];
                    if(k-1 >= 0) sum[i][j][k] += sum[i][j][k-1];
                    if(i-1 >= 0 and j-1 >= 0) sum[i][j][k] -= sum[i-1][j-1][k];
                    if(j-1 >= 0 and k-1 >= 0) sum[i][j][k] -= sum[i][j-1][k-1];
                    if(k-1 >= 0 and i-1 >= 0) sum[i][j][k] -= sum[i-1][j][k-1];
                    if(i-1 >= 0 and j-1 >= 0 and k-1 >= 0) sum[i][j][k] += sum[i-1][j-1][k-1];
                }
            }
        }

        lli answer = sum[a-1][b-1][c-1];
        for(int i=0; i<a; i++) {
            for(int j=0; j<b; j++) {
                for(int k=0; k<c; k++) {
                    for(int i2=0; i2<=i; i2++) {
                        for(int j2=0; j2<=j; j2++) {
                            for(int k2=0; k2<=k; k2++) {
                                lli candidate = sum[i][j][k];

                                if(i2-1 >= 0) candidate -= sum[i2-1][j][k];
                                if(j2-1 >= 0) candidate -= sum[i][j2-1][k];
                                if(k2-1 >= 0) candidate -= sum[i][j][k2-1];
                                if(i2-1 >= 0 and j2-1 >= 0) candidate += sum[i2-1][j2-1][k];
                                if(j2-1 >= 0 and k2-1 >= 0) candidate += sum[i][j2-1][k2-1];
                                if(k2-1 >= 0 and i2-1 >= 0) candidate += sum[i2-1][j][k2-1];
                                if(i2-1 >= 0 and j2-1 >= 0 and k2-1 >= 0) candidate -= sum[i2-1][j2-1][k2-1];

                                answer = max(answer, candidate);
                            }
                        }
                    }
                }
            }
        }
        printf("%lld\n", answer);
        if(t) printf("\n");
    }
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

vector<int> lis, lisId, lisParent;

void printLis(int u) {
    if(lisParent[u] != -1) {
        printLis(lisParent[u]);
    }
    printf(" %d", v[u]);
}

int main() {
    while(true) {
        scanf("%d", &n);
        if(!n) break;

        v = vector<int>(n);

        lis.clear();
        lisId.clear();
        lisParent = vector<int>(n);

        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }

        for(int i=0; i<n; i++) {
            int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

            if(pos < (int)lis.size()) {
                lis[pos] = v[i];
                lisId[pos] = i;
            }
            else {
                lis.push_back(v[i]);
                lisId.push_back(i);
            }

            lisParent[i] = pos ? lisId[pos-1] : -1;
        }

        printf("%d", (int)lisId.size());
        printLis(lisId[ (int)lisId.size()-1 ]);
        printf("\n");
    }
}

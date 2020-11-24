#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

vector<int> lis;
vector<int> lisId;
vector<int> parent;

void printLis(int u) {
    if(parent[u] != -1) {
        printLis(parent[u]);
    }
    printf("%d\n", v[u]);
}

int main() {
    int aux;
    while(scanf("%d", &aux) != EOF) {
        v.push_back(aux);
    }
    n = (int)v.size();

    parent = vector<int>(n);

    int lisEnd = -1;
    for(int i=0; i<n; i++) {
        int pos = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();

        if(pos < (int)lis.size()) {
            lis[pos] = v[i];
            lisId[pos] = i;
        }
        else if(pos == (int)lis.size()) {
            lis.push_back(v[i]);
            lisId.push_back(i);
        }

        if(pos == (int)lis.size()-1) {
            lisEnd = i;
        }

        parent[i] = pos ? lisId[pos-1] : -1;
    }

    printf("%d\n-\n", (int)lisId.size());
    printLis(lisEnd);
}

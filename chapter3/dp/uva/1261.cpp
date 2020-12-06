#include <bits/stdc++.h>
using namespace std;

const int MAXS = 25;
const int OK = 1, NOTOK = 2;
int offset;

char s[MAXS+1];
vector<int> seq;

vector<int> getNeighbours(int state, int u) {
    vector<int> neighbours;
    neighbours.push_back(u);

    for(int i=u-2; i>=0; i-=2) {
        if(state & (1 << (i+1))) {
            if(!(state & (1 << i))) {
                neighbours.push_back(i);
            }
        }
        else {
            break;
        }
    }
    for(int i=u+2; i<(int)seq.size(); i+=2) {
        if(state & (1 << (i-1))) {
            if(!(state & (1 << i))) {
                neighbours.push_back(i);
            }
        }
        else {
            break;
        }
    }

    return neighbours;
}

int dp[1 << MAXS];
int solve(int state) {
    if(state == (1 << (int)seq.size())-1) {
        return offset+OK;
    }

    int& ans = dp[state];
    if(ans > offset) {
        return ans;
    }

    ans = offset+NOTOK;
    for(int i=0; i<(int)seq.size(); i++) {
        if(!(state & (1 << i))) {
            vector<int> neighbours = getNeighbours(state, i);
            
            if((int)neighbours.size() > 1 or seq[i] > 1) {
                int newState = state;
                for(int n : neighbours) {
                    newState = newState | (1 << n);
                }
                if(solve(newState) == offset+OK) {
                    return ans = offset+OK;
                }
                i = neighbours[(int)neighbours.size()-1];
            }
        }
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", s);

        seq.clear();
        for(int prev=0, i=1; i<=strlen(s); i++) {
            if(i == strlen(s) or s[i] != s[i-1]) {
                seq.push_back(i-prev);
                prev = i;
            }
        }

        printf("%d\n", solve(0) == offset+OK ? 1 : 0);
        offset += 3;
    }
}

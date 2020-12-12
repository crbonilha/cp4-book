#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX_I = 1000, MAX_M = 1000;

int instruments, notes;
map<pair<int, int>, bool> instrument;
vector<int> melody;

int dp[MAX_M][MAX_I];
int solve(int note, int inst) {
    if(note == notes) {
        return 0;
    }

    int& ans = dp[note][inst];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    for(int i=0; i<instruments; i++) {
        if(instrument.find({i, melody[note]}) == instrument.end()) {
            continue;
        }
        ans = min(ans, solve(note+1, i) + int(i != inst));
    }
    return ans;
}

int main() {
    scanf("%d %d", &instruments, &notes);

    for(int i=0; i<instruments; i++) {
        int k;
        scanf("%d", &k);

        while(k--) {
            int note;
            scanf("%d", &note);
            instrument[{i, note}] = true;
        }
    }

    melody = vector<int>(notes);
    for(int i=0; i<notes; i++) {
        scanf("%d", &melody[i]);
    }

    memset(dp, -1, sizeof(dp));

    int answer = INF;
    for(int i=0; i<instruments; i++) {
        if(instrument.find({i, melody[0]}) == instrument.end()) {
            continue;
        }

        answer = min(answer, solve(0, i));
    }
    printf("%d\n", answer);
}

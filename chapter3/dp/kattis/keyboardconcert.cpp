#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAX = 1000;

int instruments, notes;
vector<int> possibleInstrument[MAX+1];
vector<int> melody;

int dp[MAX][MAX];
int solve(int note, int inst) {
    if(note == notes) {
        return 0;
    }

    int& ans = dp[note][inst];
    if(ans != -1) {
        return ans;
    }

    ans = INF;
    for(int possibleInst : possibleInstrument[ melody[note] ]) {
        ans = min(ans, solve(note+1, possibleInst) + int(possibleInst != inst));
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

            possibleInstrument[note].push_back(i);
        }
    }

    melody = vector<int>(notes);
    for(int i=0; i<notes; i++) {
        scanf("%d", &melody[i]);
    }

    memset(dp, -1, sizeof(dp));

    int answer = INF;
    for(int i=0; i<instruments; i++) {
        answer = min(answer, solve(0, i));
    }
    printf("%d\n", answer);
}

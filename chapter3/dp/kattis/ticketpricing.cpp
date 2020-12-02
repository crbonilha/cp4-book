#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

const int MAX_SEATS = 301;
const int MAX_WEEK = 53;

int tickets, weeks;
vector<ii> infos[MAX_WEEK]; // price, seats

int dp[MAX_WEEK][MAX_SEATS];
int solve(int week, int seatsTaken) {
    if(week == weeks) {
        return 0;
    }

    int& ans = dp[week][seatsTaken];
    if(ans != -1) {
        return ans;
    }

    ans = 0;
    for(ii info : infos[week]) {
        int ticketsSold = min(tickets-seatsTaken, info.second);
        ans = max(ans, solve(week+1, seatsTaken+ticketsSold) + ticketsSold*info.first);
    }
    return ans;
}

int main() {
    scanf("%d %d", &tickets, &weeks);
    weeks++;

    for(int i=0; i<weeks; i++) {
        int k;
        scanf("%d", &k);

        infos[i] = vector<ii>(k);

        for(int j=0; j<k; j++) {
            scanf("%d", &infos[i][j].first);
        }
        for(int j=0; j<k; j++) {
            scanf("%d", &infos[i][j].second);
        }
    }

    memset(dp, -1, sizeof(dp));

    ii answer = {0, 0};
    for(int i=0; i<(int)infos[0].size(); i++) {
        answer = max(answer, { solve(1, infos[0][i].second) + infos[0][i].first * infos[0][i].second, -infos[0][i].first });
    }
    printf("%d\n%d\n", answer.first, -answer.second);
}

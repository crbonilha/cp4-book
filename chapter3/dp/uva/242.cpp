#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

vector<vector<int> > deno;
vector<ii> range;

int dp[11][1001][11];
ii getDenoRange(int maxStamps, vector<int>& deno) {
    int minValue = deno[0], maxValue = deno[0];

    for(int val=minValue; val<=1000; val++) {
        bool feasibleValue = false;

        for(int stamp=0; stamp<=(int)deno.size(); stamp++) {
            for(int stampsUsed=0; stampsUsed<=maxStamps; stampsUsed++) {
                if(val == minValue) {
                    dp[stamp][val][stampsUsed] = 1;
                    feasibleValue = true;
                }
                else if(stamp == 0 or stampsUsed == 0) {
                    dp[stamp][val][stampsUsed] = 0;
                }
                else {
                    dp[stamp][val][stampsUsed] = dp[stamp-1][val][stampsUsed];

                    if(val - deno[stamp-1] >= minValue) {
                        int candidate = dp[stamp][ val-deno[stamp-1] ][stampsUsed-1];

                        dp[stamp][val][stampsUsed] = min(
                            2,
                            dp[stamp][val][stampsUsed] + candidate
                        );
                    }

                    if(dp[stamp][val][stampsUsed]) {
                        feasibleValue = true;
                    }
                }
            }
        }

        if(!feasibleValue) {
            maxValue = val-1;
            break;
        }
    }

    return {minValue, maxValue};
}

bool sortfn(const int& a, const int& b) {
    if(range[a].second - range[a].first == range[b].second - range[b].first) {
        if(deno[a].size() == deno[b].size()) {
            for(int i=(int)deno[a].size()-1; i>=0; i--) {
                if(deno[a][i] != deno[b][i]) {
                    return deno[a][i] < deno[b][i];
                }
            }
        }
        return deno[a].size() < deno[b].size();
    }
    return range[a].second - range[a].first > range[b].second - range[b].first;
}

int main() {
    while(true) {
        int maxStamps;
        scanf("%d", &maxStamps);
        if(maxStamps == 0) break;

        int sets;
        scanf("%d", &sets);

        deno = vector<vector<int> >(sets);
        for(int i=0; i<sets; i++) {
            int dSize;
            scanf("%d", &dSize);

            deno[i] = vector<int>(dSize);
            for(int j=0; j<dSize; j++) {
                scanf("%d", &deno[i][j]);
            }
        }

        range.clear();
        for(int i=0; i<sets; i++) {
            range.push_back(getDenoRange(maxStamps, deno[i]));
        }

        vector<int> p(sets);
        for(int i=0; i<sets; i++) {
            p[i] = i;
        }
        sort(p.begin(), p.end(), sortfn);

        printf("max coverage = %3d :", range[ p[0] ].second - range[ p[0] ].first);
        for(int d : deno[ p[0] ]) {
            printf(" %2d", d);
        }
        printf("\n");
    }
}

#include <bits/stdc++.h>
using namespace std;

int friends, budgetPerFriend, teaCharge, dishes;
vector<int> dishPrice, dishFavour;

bool isWithinBudget(int cost) {
    return int(ceil(double(cost + teaCharge*friends) + double(cost + teaCharge*friends)/10.0 )) <= friends * budgetPerFriend;
}

int dp[100][1101][23];
int solve(int dish, int cost, int dishesOrdered) {
    if(dish == dishes) {
        return 0;
    }

    int& ans = dp[dish][cost][dishesOrdered];
    if(ans != -1) {
        return ans;
    }

    ans = solve(dish+1, cost, dishesOrdered);

    if(dishesOrdered+1 <= friends*2 and isWithinBudget(cost + dishPrice[dish])) {
        ans = max(ans, solve(dish+1, cost+dishPrice[dish], dishesOrdered+1) + dishFavour[dish]);
    }

    if(dishesOrdered+2 <= friends*2 and isWithinBudget(cost + dishPrice[dish]*2)) {
        ans = max(ans, solve(dish+1, cost+dishPrice[dish]*2, dishesOrdered+2) + dishFavour[dish]*2);
    }

    return ans;
}

int main() {
    while(true) {
        scanf("%d %d %d %d", &friends, &budgetPerFriend, &teaCharge, &dishes);
        if(friends == 0) break;
        friends++;

        dishPrice = vector<int>(dishes);
        dishFavour = vector<int>(dishes);
        for(int i=0; i<dishes; i++) {
            scanf("%d", &dishPrice[i]);

            dishFavour[i] = 0;
            for(int j=0; j<friends; j++) {
                int aux;
                scanf("%d", &aux);

                dishFavour[i] += aux;
            }
        }

        memset(dp, -1, sizeof(dp));
        printf("%.2lf\n",
            double(solve(0, 0, 0))/double(friends));
    }
}

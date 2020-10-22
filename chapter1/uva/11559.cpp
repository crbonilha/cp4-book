#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int n, budget, hotels, weeks;
    while(scanf("%d %d %d %d", &n, &budget, &hotels, &weeks) != EOF) {
        int answer = -1;
        for(int i=0; i<hotels; i++) {
            int price;
            scanf("%d", &price);

            for(int j=0; j<weeks; j++) {
                int beds;
                scanf("%d", &beds);

                if(beds >= n and n*price <= budget) {
                    answer = answer == -1 ? n*price : min(answer, n*price);
                }
            }
        }
        if(answer == -1) {
            printf("stay home\n");
        }
        else {
            printf("%d\n", answer);
        }
    }
}

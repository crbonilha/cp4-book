#include <bits/stdc++.h>
using namespace std;

bool visiRow[9], visiDiag[17], visiDiag2[17];
int givenRow, givenCol;

int solId;
int sol[9];
void search(int col) {
    if(col == 9) {
        if(solId < 10) {
            printf(" %d", solId);
        }
        else {
            printf("%d", solId);
        }
        solId++;
        printf("      ");
        for(int i=1; i<=8; i++) {
            printf("%d%c", sol[i], " \n"[i == 8]);
        }
        return;
    }

    if(col == givenCol) {
        sol[col] = givenRow;
        search(col+1);
    }

    for(int i=1; i<=8; i++) {
        if(!visiRow[i] and !visiDiag[col+i] and !visiDiag2[8+i-col]) {
            visiRow[i] = true;
            visiDiag[col+i] = true;
            visiDiag2[8+i-col] = true;
            sol[col] = i;
            search(col+1);
            visiDiag2[8+i-col] = false;
            visiDiag[col+i] = false;
            visiRow[i] = false;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(visiRow, false, sizeof(visiRow));
        memset(visiDiag, false, sizeof(visiDiag));
        memset(visiDiag2, false, sizeof(visiDiag2));

        scanf("%d %d", &givenRow, &givenCol);

        visiRow[givenRow] = true;
        visiDiag[givenRow + givenCol] = true;
        visiDiag2[8 + givenRow - givenCol] = true;

        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        solId = 1;
        search(1);

        if(t) {
            printf("\n");
        }
    }
}

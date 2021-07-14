/*
  Problem: UVA232
  Time: 2021/7/12 9:55
  Author: Insouciant21
  Status:Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    int kase = 0;
    while (true) {
        scanf("%d", &r);
        if (r == 0)
            break;
        scanf("%d", &c);
        kase++;
        char grid[11][11];
        int id[11][11];
        for (int i = 1; i <= r; i++)
            scanf("%s", grid[i] + 1);
        int tot = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                if ((i == 1 || j == 1 || grid[i][j - 1] == '*' || grid[i - 1][j] == '*') && grid[i][j] != '*')
                    id[i][j] = ++tot;
        if (kase != 1)
            printf("\n");
        printf("puzzle #%d:\n", kase);
        printf("Across\n");
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if ((j == 1 || grid[i][j - 1] == '*') && grid[i][j] != '*') {
                    printf("%3d.", id[i][j]);
                    for (int k = j; k <= c; k++) {
                        if (grid[i][k] == '*')
                            break;
                        putchar(grid[i][k]);
                    }
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if ((i == 1 || grid[i - 1][j] == '*') && grid[i][j] != '*') {
                    printf("%3d.", id[i][j]);
                    for (int k = i; k <= r; k++) {
                        if (grid[k][j] == '*')
                            break;
                        putchar(grid[k][j]);
                    }
                    printf("\n");
                }
            }
        }
    }
    return 0;
}

/*
  Problem: UVA1225
  Time: 2021/7/11 16:33
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

int main() {
    int t = 0;
    scanf("%d", &t);
    while (t--) {
        int n = 0;
        scanf("%d", &n);
        int ans[10];
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            int p = i;
            while (p) {
                ans[p % 10]++;
                p /= 10;
            }
        }
        printf("%d", ans[0]);
        for (int i = 1; i <= 9; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }
    return 0;
}

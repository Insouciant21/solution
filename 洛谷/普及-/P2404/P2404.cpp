/*
 *  Problem: P2404
 *  Author: Insouciant21
 *  Time: 2020/9/9 19:11:18
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int ans[9];

void dfs(int sum, int cnt, int a) {
    if (sum == 0) {
        if (cnt == 2)
            return;
        for (int i = 1; i < cnt; i++) printf((i != 1) ? "+%d" : "%d", ans[i]);
        printf("\n");
    }
    if (cnt <= n) {
        for (int i = a; i <= sum; i++) {
            ans[cnt] = i;
            dfs(sum - i, cnt + 1, i);
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(n, 1, 1);
    return 0;
}

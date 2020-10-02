/*
  Problem: CF45D
  Time: 2020/10/02 09:14:53
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Space {
    int left;
    int right;
    int index;
} f[110];

int n;
int vis[int(1e7) + 10];
int ans[110];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &f[i].left, &f[i].right);
        f[i].index = i;
    }
    sort(f + 1, f + 1 + n, [](Space x, Space y) { return (x.right == y.right) ? x.left < y.left : x.right < y.right; });
    for (int i = 1; i <= n; i++) {
        for (int j = f[i].left; j <= f[i].right; j++) {
            if (!vis[j]) {
                vis[j] = 1;
                ans[f[i].index] = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
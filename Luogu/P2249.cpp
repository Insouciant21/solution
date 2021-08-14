/*
  Problem: P2249
  Time: 2020/10/11 12:06:50
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int a[int(1e6) + 1];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1, t; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1, t; i <= m; i++) {
        scanf("%d", &t);
        auto d = lower_bound(a + 1, a + 1 + n, t) - a;
        if (t != a[d])
            printf("-1 ");
        else
            printf("%d ", d);
    }
    return 0;
}

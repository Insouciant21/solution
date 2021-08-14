/*
  Problem: P2074
  Time: 2021/03/02 21:11:49
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k, t;
int ans = 0;

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        int cnt = 0;
        for (int j = max(x - t, 1); j <= min(x + t, n); j++) {
            for (int k = max(y - t, 1); k <= min(y + t, m); k++) {
                if (distance(j, k, x, y) <= t) cnt++;
            }
        }
        if (cnt > ans) ans = cnt;
    }
    printf("%d\n", ans);
    return 0;
}
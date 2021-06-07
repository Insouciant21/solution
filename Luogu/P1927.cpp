/*
  Problem: P1927
  Time: 2021/6/7 11:49
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
double ans = 1e31;
struct point {
    int x, y;
} p[1001];

double dist(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    for (int i = 1; i <= n; i++) {
        point k = p[i];
        double g = 0;
        for (int j = 1; j <= n; j++) {
            g = max(g, dist(k, p[j]));
        }
        ans = min(ans, 3.1415926535 * g * g);
    }
    printf("%.4lf\n", ans);
    return 0;
}

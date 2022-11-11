#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};
vector<Point> px;
double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
double f[1 << 16][20];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        px.push_back({x, y});
    }
    for (int i = 0; i < 1 << n; i++) fill_n(f[i], 20, 12938120123123);
    for (int i = 0; i < n; i++) f[1 << i][i] = dist({0, 0}, px[i]);
    for (int i = 1; i < 1 << n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >> j & 1) continue;
            for (int k = 0; k < n; k++)
                if (i >> k & 1)
                    f[i | 1 << j][j] = min(f[i | 1 << j][j], f[i][k] + dist(px[k], px[j]));
        }
    }
    double ans = 1230120983109;
    for (int i = 0; i < n; i++) ans = min(f[(1 << n) - 1][i], ans);
    cout << fixed << setprecision(2) << ans << endl;
}
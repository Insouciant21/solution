#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const double eps = 1e-3;
int n, m;

struct Tower {
    int x;
    double y;
    bool operator<(Tower &rhs) const { return x < rhs.x; }
} a[maxn];
int f[maxn];

double dist(Tower &lhs, Tower &rhs) {
    return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

int fa(int x) {
    return f[x] == x ? x : f[x] = fa(f[x]);
}

bool check(double mid) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++) f[i] = i;
    vector<int> px[maxn];
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if (dist(a[i], a[j]) + eps <= 2 * mid && f[fa(i)] != f[fa(j)]) f[fa(j)] = f[fa(i)];
    for (int i = 1; i <= m; i++) px[f[i]].push_back(i);
    double minDist = 12930810;
    for (int i = 1; i <= m; i++) {
        if (minDist > max(a[px[f[i]].front()].x, n - a[px[f[i]].back()].x)) {
            minDist = max(a[px[f[i]].front()].x, n - a[px[f[i]].back()].x);
        }
    }
    if (minDist + eps <= mid) return true;
    else return false;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + m);
    double l = min(n - a[m].x, a[0].x), r = n;
    double mid;
    while (l + eps < r) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(2) << mid << endl;
    return 0;
}
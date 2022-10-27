#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const double eps = 1e-3;
int n, m;

struct Tower {
    int x;
    double y;
    bool operator<(Tower &rhs) const { return (x == rhs.x) ? y < rhs.y : x < rhs.x; }
} a[maxn];
int f[maxn];

double dist(Tower &lhs, Tower &rhs) {
    return sqrt(1.0 * (lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y));
}

int fa(int x) {
    return f[x] == x ? x : f[x] = fa(f[x]);
}

void Union(int lhs, int rhs) {
    int x = fa(lhs), y = fa(rhs);
    if (x != y) f[x] = y;
}

bool check(double mid) {
    memset(f, 0, sizeof f);
    for (int i = 1; i <= m; i++) f[i] = i;
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
            if (dist(a[i], a[j]) - eps <= 2 * mid && fa(i) != fa(j)) Union(j, i);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            if (fa(i) == fa(j) && a[i].x - mid <= 0 && a[j].x + mid >= n) return true;
    return false;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    for (int i = 1; i <= m; i++) cin >> a[i].x >> a[i].y;
    sort(a + 1, a + 1 + m);
    double l = 0, r = n;
    double mid;
    while (l + eps < r) {
        mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(2) << mid << endl;
    return 0;
}
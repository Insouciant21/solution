//80

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v = 0;
    bool dis = false;
    bool operator<(const Node &rhs) const { return v < rhs.v; }
} a[120];
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        int n, maxv = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].v;
            maxv = max(maxv, a[i].v);
            a[i].dis = false;
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            if (a[i].dis) continue;
            for (int j = i + 1; j <= n; j++) {
                if (a[j].dis) continue;
                if (a[j].v % a[i].v == 0) a[j].dis = true;
            }
        }
        set<int> p;
        int ans = 29381029;
        for (int i = 1, q = 0; i <= n; i++) {
            if (a[i].dis) continue;
            q++, p.insert(a[i].v);
            set<int> k = p;
            for (int j : k)
                for (int o = a[i].v; o + j <= maxv; o += a[i].v) p.insert(j + o);
            int cnt = 0;
            for (int j = i + 1; j <= n; j++) {
                if (a[j].dis) continue;
                if (p.find(a[j].v) == p.end()) cnt++;
                else a[j].dis = true;
            }
            ans = min(ans, q + cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
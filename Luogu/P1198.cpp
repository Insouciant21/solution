#include <bits/stdc++.h>

using namespace std;

int m, d;
const int maxn = 2e5 + 100;
long long a[maxn];

struct IntervalTree {
    long long maxv[maxn * 4];
    long long query(int o, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) return maxv[o];
        int mid = (l + r) >> 1;
        long long res = numeric_limits<long long>::min();
        if (qL <= mid) res = max(res, query(o * 2, l, mid, qL, qR));
        if (qR > mid) res = max(res, query(o * 2 + 1, mid + 1, r, qL, qR));
        return res;
    }
    void set(int o, int l, int r, long long v, int p) {
        if (l == p && l == r) {
            maxv[o] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) set(o * 2, l, mid, v, p);
        else set(o * 2 + 1, mid + 1, r, v, p);
        maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
    }
} st;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d\n", &m, &d);
    long long t = 0;
    int x, c = 0;
    fill_n(st.maxv, maxn, -0x3f3f3f3f3f3f3f);
    for (int i = 1; i <= m; i++) {
        char opt;
        scanf("%c %d\n", &opt, &x);
        if (opt == 'Q') printf("%lld\n", t = st.query(1, 1, m + 1, c - x + 1, c));
        else {
            st.set(1, 1, m + 1, (x + t) % d, c + 1);
            c++;
        }
    }
    return 0;
}

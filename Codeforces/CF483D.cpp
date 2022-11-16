#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m;
int a[maxn];

struct IntervalTree {
    long long sum[maxn * 4];
    long long maxv[maxn * 4];
    int p, qL, qR;
    void maintain(int o) {
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
    }
    void buildTree(int o, int l, int r) {
        if (l == r) {
            sum[o] = maxv[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(o * 2, l, mid);
        buildTree(o * 2 + 1, mid + 1, r);
        maintain(o);
    }
    void set(int o, int l, int r, int v) {
        if (l == r && l == p) sum[o] = v, maxv[o] = v;
        else {
            int mid = (l + r) >> 1;
            if (p <= mid) set(o * 2, l, mid, v);
            else set(o * 2 + 1, mid + 1, r, v);
            maintain(o);
        }
    }
    void modulo(int o, int l, int r, int x) {
        if (qL <= l && r <= qR && (maxv[o] < x)) return;
        if (l == r) sum[o] %= x, maxv[o] %= x;
        else {
            int mid = (l + r) >> 1;
            if (qL <= mid) modulo(o * 2, l, mid, x);
            if (mid < qR) modulo(o * 2 + 1, mid + 1, r, x);
            maintain(o);
        }
    }
    long long query(int o, int l, int r) {
        if (qL <= l && r <= qR) return sum[o];
        else {
            int mid = (l + r) >> 1;
            long long res = 0;
            if (qL <= mid) res += query(o * 2, l, mid);
            if (mid < qR) res += query(o * 2 + 1, mid + 1, r);
            return res;
        }
    }
} st;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    st.buildTree(1, 1, n);
    while (m--) {
        int type, x;
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d %d", &st.qL, &st.qR);
            printf("%lld\n", st.query(1, 1, n));
        }
        if (type == 2) {
            scanf("%d %d %d", &st.qL, &st.qR, &x);
            st.modulo(1, 1, n, x);
        }
        if (type == 3) {
            scanf("%d %d", &st.p, &x);
            st.set(1, 1, n, x);
        }
    }
    return 0;
}

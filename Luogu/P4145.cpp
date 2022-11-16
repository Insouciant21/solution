#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int n, m;
long long a[maxn];

struct IntervalTree {
    long long sum[maxn * 4], maxv[maxn * 4];
    void buildTree(int o, int l, int r) {
        if (l == r) {
            maxv[o] = sum[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(o * 2, l, mid);
        buildTree(o * 2 + 1, mid + 1, r);
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
    }
    void edit(int o, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR && (maxv[o] == 1 || maxv[o] == 0)) return;
        if (l == r) sum[o] = floor(sqrt(sum[o])), maxv[o] = int(sqrt(maxv[o]));
        else {
            int mid = (l + r) >> 1;
            if (qL <= mid) edit(o * 2, l, mid, qL, qR);
            if (mid < qR) edit(o * 2 + 1, mid + 1, r, qL, qR);
            sum[o] = sum[o * 2] + sum[o * 2 + 1], maxv[o] = max(maxv[o * 2], maxv[o * 2 + 1]);
        }
    }
    long long query(int o, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) return sum[o];
        int mid = (l + r) >> 1;
        long long res = 0;
        if (qL <= mid) res += query(o * 2, l, mid, qL, qR);
        if (mid < qR) res += query(o * 2 + 1, mid + 1, r, qL, qR);
        return res;
    }
} st;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", a + i);
    st.buildTree(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int k, l, r;
        scanf("%d %d %d", &k, &l, &r);
        if (l > r) swap(l, r);
        if (k == 0) st.edit(1, 1, n, l, r);
        if (k == 1) printf("%lld\n", st.query(1, 1, n, l, r));
    }
    return 0;
}

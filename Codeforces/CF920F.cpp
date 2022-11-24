#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 10, maxnum = 1e6 + 10;
int a[maxn], d[maxnum];
int n, m, p[maxn], num[maxnum];
bitset<maxnum> vis;
void prime() {
    d[1] = 1;
    int tot = 0;
    for (int i = 2; i < maxnum; i++) {
        if (!vis[i]) vis[i] = true, p[++tot] = i, d[i] = 2, num[i] = 1;
        for (int j = 1; j <= tot && i <= maxnum / p[j]; j++) {
            vis[p[j] * i] = true;
            if (i % p[j] == 0) {
                num[i * p[j]] = num[i] + 1;
                d[i * p[j]] = d[i] / num[i * p[j]] * (num[i * p[j]] + 1);
                break;
            }
            else num[i * p[j]] = 1, d[i * p[j]] = d[i] * 2;
        }
    }
}

struct IntervalTree {
    long long sum[maxn * 4];
    long long maxd[maxn * 4];
    int ql, qr;
    void maintain(int o) {
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        maxd[o] = max(maxd[o * 2], maxd[o * 2 + 1]);
    }
    void buildTree(int o, int l, int r) {
        if (l == r) {
            sum[o] = maxd[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(o * 2, l, mid);
        buildTree(o * 2 + 1, mid + 1, r);
        maintain(o);
    }
    void edit(int o, int l, int r) {
        if (ql <= l && r <= qr && maxd[o] <= 2) return;
        if (l == r) {
            sum[o] = d[sum[o]];
            maxd[o] = sum[o];
        }
        else {
            int mid = (l + r) >> 1;
            if (ql <= mid) edit(o * 2, l, mid);
            if (mid < qr) edit(o * 2 + 1, mid + 1, r);
            maintain(o);
        }
    }
    long long query(int o, int l, int r) {
        if (ql <= l && r <= qr) return sum[o];
        int mid = (l + r) >> 1;
        long long res = 0;
        if (ql <= mid) res += query(o * 2, l, mid);
        if (mid < qr) res += query(o * 2 + 1, mid + 1, r);
        return res;
    }
} st;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    prime();
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    st.buildTree(1, 1, n);
    while (m--) {
        int opt;
        scanf("%d %d %d", &opt, &st.ql, &st.qr);
        if (opt == 1) st.edit(1, 1, n);
        else printf("%lld\n", st.query(1, 1, n));
    }
    return 0;
}

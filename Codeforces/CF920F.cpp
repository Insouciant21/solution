#include <bits/stdc++.h>

using namespace std;
const int maxn = 3e5 + 10, maxnum = 1e6 + 10;
int a[maxn], d[maxn];
int n, m;
bitset<maxnum> numlist;
void prime() {
    numlist.set();
    numlist[0] = false;
    int g = int(sqrt(maxnum));
    for (int i = 2; i < g; i++) {
        if (numlist[i])
            for (int j = i * i; j < maxnum; j += i) numlist[j] = false;
    }
}

int cnt(int x) {
    if (numlist[x]) return 1;
    int res = 0, c = int(sqrt(x));
    for (int i = 1; i <= c; i++)
        if (x % i == 0) res += 2;
    if (c * c == x) res--;
    return res;
}

struct IntervalTree {
    long long sum[maxn * 4];
    int maxd[maxn * 4];
    int ql, qr;
    void maintain(int o) {
        sum[o] = sum[o * 2] + sum[o * 2 + 1];
        maxd[o] = max(maxd[o * 2], maxd[o * 2 + 1]);
    }
    void buildTree(int o, int l, int r) {
        if (l == r) {
            sum[o] = a[l];
            maxd[o] = d[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(o * 2, l, mid);
        buildTree(o * 2 + 1, mid + 1, r);
        maintain(o);
    }
    void edit(int o, int l, int r) {
        if (ql <= l && r <= qr && maxd[o] == 1) return;
        if (l == r) {
            sum[o] = d[l];
            d[l] = cnt(d[l]);
            maxd[o] = d[l];
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
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        d[i] = cnt(a[i]);
    }
    st.buildTree(1, 1, n);
    while (m--) {
        int opt;
        scanf("%d %d %d", &opt, &st.ql, &st.qr);
        if (opt == 1) st.edit(1, 1, n);
        else printf("%lld\n", st.query(1, 1, n));
    }
    return 0;
}

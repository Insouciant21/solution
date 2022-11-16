#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
struct Edge {
    int u, v;
};
vector<Edge> e[maxn];
int n, m, R, p;
int w[maxn], hson[maxn], sz[maxn], dep[maxn];
int fa[maxn], dfn[maxn], rk[maxn], top[maxn], bottom[maxn];
void dfs1(int u) {
    hson[u] = -1, sz[u] = 1;
    for (auto ex : e[u]) {
        if (!dep[ex.v]) {
            dep[ex.v] = dep[u] + 1;
            fa[ex.v] = u;
            dfs1(ex.v);
            sz[u] += sz[ex.v];
            if (hson[u] == -1 || sz[ex.v] > sz[hson[u]]) hson[u] = ex.v;
        }
    }
}
int cnt = 0;
void dfs2(int u, int tp) {
    top[u] = tp, cnt++;
    dfn[u] = cnt, rk[cnt] = u;
    if (hson[u] == -1) return;
    dfs2(hson[u], tp);
    bottom[hson[u]] = cnt;
    for (auto ex : e[u]) {
        if (ex.v == hson[u] || ex.v == fa[u]) continue;
        dfs2(ex.v, ex.v);
        bottom[ex.v] = cnt;
    }
}

struct IntervalTree {
    int sum[maxn * 5], b[maxn * 5];
    void build(int o, int l, int r) {
        if (l == r) {
            sum[o] = w[rk[l]];
            return;
        }
        build(o * 2, l, (l + r) >> 1);
        build(o * 2 + 1, ((l + r) >> 1) + 1, r);
        sum[o] = (sum[o * 2] + sum[o * 2 + 1]) % p;
        b[o] = 0;
    }
    void pushdown(int o, int l, int r) {
        int lr = o * 2, rr = o * 2 + 1;
        int mid = (l + r) >> 1;
        sum[lr] += (mid - l + 1) * b[o], sum[rr] += (r - mid) * b[o];
        sum[lr] %= p, sum[rr] %= p;
        b[lr] += b[o], b[rr] += b[o];
        b[o] = 0;
    }
    void add(int o, int l, int r, int v, int qL, int qR) {
        if (qL <= l && r <= qR) {
            sum[o] += (r - l + 1) * v;
            b[o] += v;
            return;
        }
        pushdown(o, l, r);
        int mid = (l + r) >> 1;
        if (qL <= mid) add(o * 2, l, mid, v, qL, qR);
        if (mid < qR) add(o * 2 + 1, mid + 1, r, v, qL, qR);
        sum[o] = (sum[o * 2] + sum[o * 2 + 1]) % p;
    }
    int query(int o, int l, int r, int qL, int qR) {
        if (qL <= l && r <= qR) return sum[o];
        pushdown(o, l, r);
        int mid = (l + r) >> 1, res = 0;
        if (qL <= mid) res = (res + query(o * 2, l, mid, qL, qR)) % p;
        if (mid < qR) res = (res + query(o * 2 + 1, mid + 1, r, qL, qR)) % p;
        return res % p;
    }
} st;

void SAdd(int x, int y, int z) {
    int fx = top[x], fy = top[y];
    while (fx != fy) {
        if (dep[fx] >= dep[fy]) st.add(1, 1, n, z, dfn[fx], dfn[x]), x = fa[fx];
        else st.add(1, 1, n, z, dfn[fy], dfn[y]), y = fa[fy];
        fx = top[x], fy = top[y];
    }
    if (dfn[x] < dfn[y]) st.add(1, 1, n, z, dfn[x], dfn[y]);
    else st.add(1, 1, n, z, dfn[y], dfn[x]);
}
int SQuery(int x, int y) {
    int fx = top[x], fy = top[y];
    int res = 0;
    while (fx != fy) {
        if (dep[fx] >= dep[fy]) res = (res + st.query(1, 1, n, dfn[fx], dfn[x])) % p, x = fa[fx];
        else res = (res + st.query(1, 1, n, dfn[fy], dfn[y])) % p, y = fa[fy];
        fx = top[x], fy = top[y];
    }
    if (dfn[x] < dfn[y]) res = (res + st.query(1, 1, n, dfn[x], dfn[y])) % p;
    else res = (res + st.query(1, 1, n, dfn[y], dfn[x])) % p;
    return res;
}
inline void SubAdd(int x, int z) {
    st.add(1, 1, n, z, dfn[x], bottom[x]);
}
inline int SubQuery(int x) {
    return st.query(1, 1, n, dfn[x], bottom[x]);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d %d %d", &n, &m, &R, &p);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v);
        e[u].push_back({u, v});
        e[v].push_back({v, u});
    }
    dep[R] = 1;
    dfs1(R), dfs2(R, R);
    bottom[R] = cnt;
    st.build(1, 1, n);
    while (m--) {
        int opt;
        scanf("%d", &opt);
        if (opt == 1) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            SAdd(x, y, z);
        }
        if (opt == 2 || opt == 3) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (opt == 3) SubAdd(x, y);
            else printf("%d\n", SQuery(x, y) % p);
        }
        if (opt == 4) {
            int x;
            scanf("%d", &x);
            printf("%d\n", SubQuery(x) % p);
        }
    }
    return 0;
}

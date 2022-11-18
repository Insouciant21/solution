#include <bits/stdc++.h>

using namespace std;
const int maxn = 51000;
int a[maxn];
struct IntervalTree {
    struct Node {
        int lft, max_sum;
        int rht, sum;
    } nodes[maxn * 4];
    static void maintain(Node &f, Node &ls, Node &rs) {
        f.sum = ls.sum + rs.sum;
        f.max_sum = max(max(ls.max_sum, rs.max_sum), ls.rht + rs.lft);
        f.lft = max(ls.lft, ls.sum + rs.lft);
        f.rht = max(rs.rht, rs.sum + ls.rht);
    }
    void buildTree(int o, int l, int r) {
        if (l == r) {
            Node &f = nodes[o];
            f.sum = f.max_sum = f.lft = f.rht = a[l];
            return;
        }
        int m = (l + r) >> 1;
        buildTree(o * 2, l, m);
        buildTree(o * 2 + 1, m + 1, r);
        maintain(nodes[o], nodes[o << 1], nodes[o << 1 | 1]);
    }
    int p, ql, qr;
    void edit(int o, int l, int r, int v) {
        if (l == p && r == l) {
            Node &f = nodes[o];
            f.sum = f.max_sum = f.lft = f.rht = v;
            return;
        }
        int m = (l + r) >> 1;
        if (p <= m) edit(o << 1, l, m, v);
        else edit(o << 1 | 1, m + 1, r, v);
        maintain(nodes[o], nodes[o << 1], nodes[o << 1 | 1]);
    }
    Node query(int o, int l, int r) {
        if (ql <= l && r <= qr) return nodes[o];
        int m = (l + r) >> 1;
        if (qr <= m) return query(o << 1, l, m);
        if (ql > m) return query(o << 1 | 1, m + 1, r);
        Node ans {}, ls {}, rs {};
        ls = query(o << 1, l, m), rs = query(o << 1 | 1, m + 1, r);
        maintain(ans, ls, rs);
        return ans;
    }
} st;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    st.buildTree(1, 1, n);
    scanf("%d", &q);
    while (q--) {
        int opt, x;
        scanf("%d", &opt);
        if (opt == 0) {
            scanf("%d %d", &st.p, &x);
            st.edit(1, 1, n, x);
        }
        else {
            scanf("%d %d", &st.ql, &st.qr);
            printf("%d\n", st.query(1, 1, n).max_sum);
        }
    }
    return 0;
}

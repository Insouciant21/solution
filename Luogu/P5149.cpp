#include <bits/stdc++.h>

using namespace std;
int n;
struct IntervalTree {
    int sum[500000]{};
    inline void maintain(int o) { sum[o] = sum[o << 1] + sum[o << 1 | 1]; }
    int p{};
    void edit(int o, int l, int r) {
        if (l == r && l == p) {
            sum[o] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) edit(o << 1, l, mid);
        else edit(o << 1 | 1, mid + 1, r);
        maintain(o);
    }
    int ql{}, qr = n;
    int query(int o, int l, int r) {
        if (ql <= l && r <= qr) return sum[o];
        else {
            int mid = (l + r) >> 1;
            int ans = 0;
            if (ql <= mid) ans += query(o << 1, l, mid);
            if (mid < qr) ans += query(o << 1 | 1, mid + 1, r);
            return ans;
        }
    }
} st;
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    map<string, int> p;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        p[s] = i;
    }
    long long ans = 0;
    st.qr = n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        st.p = p[s], st.ql = st.p + 1;
        st.edit(1, 1, n);
        ans += st.query(1, 1, n);
    }
    cout << ans << endl;
    return 0;
}

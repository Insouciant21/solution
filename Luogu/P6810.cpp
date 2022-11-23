#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
struct IntervalTree {
    int sumSq[maxn * 4];
    int sum[maxn * 4];
    int ql, qr;
    void maintain(int o) {
        int ls = o << 1, rs = o << 1 | 1;
        sum[o] = sum[ls] + sum[rs];
    }
    void buildTree(int o, int l, int r) {
        if (l == r) {
            sumSq[o] = a[l] * a[l], sum[o] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        buildTree(o << 1, l, mid);
        buildTree(o << 1 | 1, mid + 1, r);
        maintain(o);
    }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    return 0;
}
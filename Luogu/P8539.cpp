#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * 1000020;

int A[maxn];

int f[2][maxn][30];

int n, m, v;


int p[maxn];

bool check(int i) {
    if (A[i] >= p[i]) return true;
    else return false;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n >> m >> v;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (check(i)) p[i] = A[i];
        else p[i] += v;
    }
    RMQ(A, f[0]), RMQ(p, f[1]);
    int ans = 0, ret = 0;
    while (m--) {
        int x, k;
        cin >> x >> k;
        int s = 0;
        if (x + k - 1 <= n) {
            int e = query(x, x + k - 1, f[0]);
            s = max(e, p[x]);
        }
        ans ^= s, ret += s;
    }
    cout << ans << " " << ret << endl;
    return 0;
}
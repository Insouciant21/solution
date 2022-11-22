#include <bits/stdc++.h>

using namespace std;

struct mat {
    static const int maxr = 16, maxc = 16;
    long long m[maxr][maxc];
    int r, c;
};

mat mul(const mat &lhs, const mat &rhs, int modp) {
    mat res {};
    res.r = lhs.r, res.c = rhs.c;
    for (int i = 0; i < lhs.r; i++)
        for (int j = 0; j < rhs.c; j++)
            for (int k = 0; k < lhs.c; k++) res.m[i][j] = (res.m[i][j] + lhs.m[i][k] * rhs.m[k][j] % modp) % modp;
    return res;
}

mat quickPow(mat a, long long s, int p) {
    mat res {};
    res.r = res.c = a.r;
    for (int i = 0; i < res.r; i++) res.m[i][i] = 1;
    while (s) {
        if (s & 1) res = mul(res, a, p);
        a = mul(a, a, p);
        s >>= 1;
    }
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    long long d, n, m;
    while (cin >> d >> n >> m && d) {
        mat fx {}, s {};
        fx.r = fx.c = d, s.r = d, s.c = 1;
        for (int i = 0; i < d; i++) {
            cin >> fx.m[0][i];
            fx.m[0][i] %= m;
        }
        for (int i = 1; i < d; i++) fx.m[i][i - 1] = 1;
        for (int i = 1; i <= d; i++) {
            cin >> s.m[d - i][0];
            s.m[d - i][0] %= m;
        }
        if (n > d) cout << mul(quickPow(fx, n - d, m), s, m).m[0][0] << "\n";
        else cout << s.m[d - n][0] << "\n";
    }
    return 0;
}

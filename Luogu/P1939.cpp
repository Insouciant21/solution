#include <bits/stdc++.h>

using namespace std;

struct mat {
    static const int maxr = 16, maxc = 16;
    long long m[maxr][maxc];
    int r, c;
};

int modp = 1e9 + 7;

mat mul(const mat &lhs, const mat &rhs) {
    mat res {};
    res.r = lhs.r, res.c = rhs.c;
    for (int i = 0; i < lhs.r; i++)
        for (int j = 0; j < rhs.c; j++)
            for (int k = 0; k < lhs.c; k++) res.m[i][j] = (res.m[i][j] + lhs.m[i][k] * rhs.m[k][j] % modp) % modp;
    return res;
}

mat quickPow(mat a, long long s) {
    mat res {};
    res.r = res.c = a.r;
    for (int i = 0; i < res.r; i++) res.m[i][i] = 1;
    while (s) {
        if (s & 1) res = mul(res, a);
        a = mul(a, a);
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
    long long n;
    mat fx {}, s {};
    fx.r = fx.c = 3, s.r = 3, s.c = 1;
    fx.m[0][0] = fx.m[0][2] = 1;
    for (int i = 1; i < 3; i++) fx.m[i][i - 1] = 1;
    s.m[0][0] = s.m[1][0] = s.m[2][0] = 1;
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n > 3) cout << mul(quickPow(fx, n - 3), s).m[0][0] << "\n";
        else cout << 1 << "\n";
    }
    return 0;
}
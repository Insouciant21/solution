#include <bits/stdc++.h>

using namespace std;
struct Matrix {
    int m[2][2] {};
    int r {}, c {};
};

Matrix mul(const Matrix &lhs, const Matrix &rhs, int modp) {
    Matrix res;
    res.r = lhs.r, res.c = rhs.c;
    for (int i = 0; i < lhs.r; i++)
        for (int j = 0; j < rhs.c; j++)
            for (int k = 0; k < lhs.c; k++) res.m[i][j] = (res.m[i][j] + lhs.m[i][k] * rhs.m[k][j] % modp) % modp;
    return res;
}

Matrix quickPow(Matrix a, long long b, int p) {
    Matrix res;
    for (int i = 0; i < 2; ++i) res.m[i][i] = 1;
    res.r = res.c = 2;
    while (b) {
        if (b & 1) res = mul(res, a, p);
        a = mul(a, a, p);
        b >>= 1;
    }
    return res;
}

unsigned long long quickPow(unsigned long long a, unsigned long long b, int p) {
    unsigned long long res = 1;
    a %= p;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    scanf("%d", &T);
    Matrix fibx, fb;
    fibx.m[0][0] = fibx.m[0][1] = fibx.m[1][0] = 1, fibx.r = fibx.c = 2;
    fb.m[0][0] = 1, fb.r = 2, fb.c = 1;
    while (T--) {
        map<pair<int, int>, int> px;
        unsigned long long a, b;
        int p, g = 0;
        scanf("%llu %llu %d", &a, &b, &p);
        for (int i = 2; i <= 10000; i++) {
            Matrix res = quickPow(fibx, i - 2, p);
            res = mul(res, fb, p);
            if (px.count({res.m[0][0], res.m[1][0]})) {
                g = i - px[{res.m[0][0], res.m[1][0]}];
                break;
            }
            px[{res.m[0][0], res.m[1][0]}] = i;
        }
        long long f = quickPow(a, b, g);
        Matrix res = mul(quickPow(fibx, f - 1, p), fb, p);
        printf("%d\n", res.m[0][0]);
    }
    return 0;
}

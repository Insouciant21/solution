#include <bits/stdc++.h>
using namespace std;

void exgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) x = 1, y = 0;
    else exgcd(b, a % b, y, x), y -= x * (a / b);
}

int r[20], c[20];
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    long long m = 1;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> r[i] >> c[i];
        m *= r[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long m_i = m / r[i], inM, o;
        exgcd(m_i, r[i], inM, o);
        inM = (inM + r[i]) % r[i];
        ans = (ans + inM * c[i] * m_i % m) % m;
    }
    cout << ans << endl;
}
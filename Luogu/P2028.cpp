#include <bits/stdc++.h>

using namespace std;

int n, k;
unsigned long long p;

unsigned long long f[10010][1010];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k >> p;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) f[i][0] = f[0][i] = 0, f[i][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++) f[i][j] = (j * f[i - 1][j] + f[i - 1][j - 1]) % p;
    cout << f[n][k] % p << endl;
    return 0;
}
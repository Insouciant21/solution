#include <bits/stdc++.h>

using namespace std;
long long f[2][201][201][2];
int modp = 1e9 + 7;
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string a, b;
    int n, m, k;
    cin >> n >> m >> k;
    cin >> a >> b;
    int s = 0;
    f[0][0][0][0] = f[1][0][0][0] = 1;
    for (int i = 1; i <= n; i++, s ^= 1) {
        for (int j = 1; j <= m; j++) {
            for (int p = 1; p <= k; p++) {
                f[s][j][p][0] = (f[s ^ 1][j][p][0] + f[s ^ 1][j][p][1]) % modp;
                if (a[i - 1] == b[j - 1])
                    f[s][j][p][1] =
                        (f[s ^ 1][j - 1][p - 1][0] + f[s ^ 1][j - 1][p - 1][1] % modp + f[s ^ 1][j - 1][p][1]) % modp;
                else f[s][j][p][1] = 0;
            }
        }
    }
    cout << (f[!(n & 1)][m][k][0] + f[!(n & 1)][m][k][1]) % modp << endl;
    return 0;
}

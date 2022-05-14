/*
 *  Problem: UVa11137
 *  Author: Insouciant21
 *  Date: 2022/4/21
 */

#include <bits/stdc++.h>

using namespace std;

long long f[23][11001];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    f[0][0] = 1;
    for (int i = 1; i <= 21; i++) {
        for (int j = 0; j <= 10000; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= i * i * i) f[i][j] += f[i][j - i * i * i];
        }
    }
    int n;
    while (cin >> n) cout << f[21][n] << endl;
    return 0;
}

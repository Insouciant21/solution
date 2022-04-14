/*
 *  Problem: UVA11538
 *  Author: Insouciant21
 *  Date: 2022/4/14
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    unsigned long long n, m;
    while (true) {
        cin >> n >> m;
        if (n == m && m == 0) break;
        if (n > m) swap(n, m);
        cout << n * m * (n + m - 2) + 2 * n * (n - 1) * (3 * m - n - 1) / 3 << endl;
    }
    return 0;
}

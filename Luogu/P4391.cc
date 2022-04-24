/*
 *  Problem: P4391
 *  Author: Insouciant21
 *  Date: 2022/4/24
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int L;
    string s;
    cin >> L >> s;
    int f[int(1e6) + 100];
    f[0] = f[1] = 0;
    for (int i = 1; i < L; i++) {
        int j = f[i];
        while (j && s[i] != s[j]) j = f[j];
        f[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
    cout << L - f[L] << endl;
    return 0;
}

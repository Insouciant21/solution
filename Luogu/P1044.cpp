#include <bits/stdc++.h>

using namespace std;

int f[100];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    f[0] = f[1] = 1;
    cin >> n;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < i; j++) f[i] += f[i - j - 1] * f[j];
    cout << f[n] << endl;
    return 0;
}
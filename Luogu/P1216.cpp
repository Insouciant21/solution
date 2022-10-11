#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    int s[1010][1010];
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> s[i][j];
    int f[1010];
    memset(f, 0, sizeof f);
    for (int i = n ; i >= 1; i--)
        for (int j = 1; j <= i; j++) f[j] = max(f[j], f[j + 1]) + s[i][j];
    cout << f[1] << endl;
    return 0;
}
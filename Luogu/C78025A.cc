#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    long long f = 1;
    long long b = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        f = f % (int(1e9) + 7) * (b = (2 * b + 1) % (int(1e9) + 7)) % (int(1e9) + 7);
    cout << f << endl;
}

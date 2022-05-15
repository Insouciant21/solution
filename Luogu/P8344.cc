#include <bits/stdc++.h>

using namespace std;
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        long long x, y, z;
        cin >> x >> y >> z;
        if ((x > z) || (x == z && (z) * (z - 1) / 2 < y) || (x < z && x * (2 * z - x - 1) / 2 + z - x < y))
            cout << "Merry" << endl;
        else cout << "Renko" << endl;
    }
}

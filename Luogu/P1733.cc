#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int l = 1, r = int(1e9);
    int m = (l + r) / 2, res;
    cout << m << endl;
    while (true && l <= r) {
        cin >> res;
        if (res == 0) break;
        if (res == -1) l = m + 1;
        if (res == 1) r = m - 1;
        m = (l + r) / 2;
        cout << m << endl;
    }
}

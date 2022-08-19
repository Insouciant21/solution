#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        long long s, m;
        cin >> s >> m;
        if (m == 1 || s % 2 != 0) cout << -1 << endl;
        else cout << 2 << " " << s / 2 << " " << s / 2 << endl;
    }
}

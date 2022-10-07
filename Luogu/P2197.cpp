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
        int n, sum = 0;
        cin >> n;
        for (int i = 0, t; i < n; i++) {
            cin >> t;
            sum ^= t;
        }
        if (sum) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
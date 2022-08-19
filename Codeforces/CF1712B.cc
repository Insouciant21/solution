#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2) cout << 1 << " ";
        for (int i = n % 2; i < n; i += 2) cout << i + 2 << " " << i + 1 << " ";
        cout << endl;
    }
}

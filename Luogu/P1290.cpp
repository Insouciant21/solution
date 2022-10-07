#include <bits/stdc++.h>

using namespace std;

bool SG(int n, int m) {
    if (!m) return false;
    if (n / m == 1) return !SG(m, n % m);
    return true;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        if (SG(max(a, b), min(a, b))) cout << "Stan wins" << endl;
        else cout << "Ollie wins" << endl;
    }
    return 0;
}
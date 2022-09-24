#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n, m;
    int m1 = 2 * (1e9), m2 = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        m1 = min(m1, a), m2 = max(m2, a);
    }
    if (m2 < 2 && m > 0) m2 += 2, m--;
    cout << (1LL * m2 * (1 << m)) - m1 << endl;
}

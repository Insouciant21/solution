#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    long long p;
    cin >> p;
    for (int i = 1; i < int(1e6) * 3; i++) {
        long long k;
        cin >> k;
        p = p ^ k;
    }
    cout << p << endl;
}

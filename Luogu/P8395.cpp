#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i <= n / 4; i++) {
        int p = n - i * 4;
        if (p % 5 == 0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
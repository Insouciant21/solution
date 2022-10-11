#include <bits/stdc++.h>
using namespace std;

int SG(int m, int n) {
    set<int> vis;
    int a = m - 1, pos = 0;
    while (a) {
        if (a % 2) vis.insert(pos);
        a /= 2;
        pos++;
    }
    a = n - 1, pos = 0;
    while (a) {
        if (a % 2) vis.insert(pos);
        a /= 2;
        pos++;
    }
    for (int i = 0; i < 50; i++)
        if (!vis.count(i)) return i;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, sum = 0;
        cin >> n;
        for (int i = 0, a, b; i < n / 2; i++) {
            cin >> a >> b;
            sum ^= SG(a, b);
        }
        if (sum) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
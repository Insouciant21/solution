#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            pos1 = i + 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {pos2++;
        if (a[i] == 0) break;
    }
    if ((pos1 != 1 || pos2 != 1) && (pos1 % 2 == 0 || pos2 % 2 == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
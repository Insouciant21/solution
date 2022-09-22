#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    int ans1 = 0, ans2 = 1;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        b.push_back(t);
        if (t != a[i]) ans1++;
        if (t != a[n - i - 1]) ans2++;
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}
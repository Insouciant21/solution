#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    vector<int> a;
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());
    int sum = a[0] * (n - 1);
    for (int i = 1; i < n; i++) sum += a[i] * (n - i);
    cout << sum << endl;
    return 0;
}
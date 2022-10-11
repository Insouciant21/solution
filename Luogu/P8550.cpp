#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        for (int i = 0, t; i < n; i++) {
            cin >> t;
            a.push_back(t);
        }
        a.erase(unique(a.begin(), a.end()), a.end());
        if (a.size() == 1) {
            if (x * a[0] >= 0 || x / a[0] * a[0] != x) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "Yes" << endl;
    }
}
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
        int n, k;
        vector<int> p;
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            p.push_back(t);
        }
        sort(p.begin(), p.begin() + k, greater<int>());
        sort(p.begin() + k, p.end());
        int p1 = 0, p2 = k;
        int cnt = 0;
        while (p[p1] > p[p2] && k != n && p1 < k && p2 < n) {
            cnt++;
            p1++, p2++;
        }
        cout << cnt << endl;
    }
}

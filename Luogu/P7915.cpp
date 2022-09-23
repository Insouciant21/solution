// wa

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0, t; i < n; i++) {
            cin >> t;
            a.push_back(t);
        }
        deque<int> p[2];
        int flag = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[0]) {
                flag = 1;
                continue;
            }
            if (flag) p[flag].push_front(a[i]);
            else p[flag].push_back(a[i]);
        }
        string ans = "L";
        bool failed = false;
        cout << "c" << endl;
        while (!p[0].empty() && !p[1].empty()) {
            if (!p[1].empty() && (p[0].front() == p[0].back() || !p[1].empty() && p[0].front() == p[1].back())) {
                    ans += "L";
                    if (p[0].front() == p[0].back()) p[0].pop_back();
                    else p[1].pop_back();
                    p[0].pop_front();
                }
            else if (!p[1].empty() && (p[1].front() == p[1].back() || (!p[0].empty() && p[1].front() == p[0].back()))) {
                ans += "R";
                if (p[1].front() == p[1].back()) p[1].pop_back();
                else p[0].pop_back();
                p[1].pop_front();
            }
            else {
                failed = true;
                break;
            }
        }
        if (failed) cout << "-1" << endl;
        else {
            ans += "L";
            cout << ans << endl;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int kase = 0;
    while (true) {
        cin >> n;
        if (kase) cout << endl;
        if (n == 0) break;
        kase++;
        while (true) {
            queue<int> a;
            for (int i = 1; i <= n; i++) a.push(i);
            queue<int> b;
            int t;
            cin >> t;
            if (t == 0) break;
            b.push(t);
            for (int i = 1; i < n; i++) {
                cin >> t;
                b.push(t);
            }
            stack<int> c;
            while (!b.empty()) {
                bool ok = false;
                while (true) {
                    if (!c.empty() && c.top() == b.front()) {
                        ok = true;
                        c.pop();
                        b.pop();
                        break;
                    }
                    if (a.empty()) break;
                    c.push(a.front());
                    a.pop();
                }
                if (!ok) break;
            }
            if (b.empty()) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}

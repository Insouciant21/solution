#include <bits/stdc++.h>

using namespace std;

int n;
vector<int>p;

int main() {
    cin >> n;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        p.push_back(t);
    }
    int ans = 0;
    bool is = false;
    for (int m = 0; m < n; m++) {
        for (int i = 0; i < n; i++) {
            is = 0;
            for (int j = i + 1; j < n; j++) {
                if (p[m] == p[i] + p[j]) { ans++; is = 1; break; }
            }
            if (is) break;
        }
    }
    cout << ans << endl;
    return 0;
}

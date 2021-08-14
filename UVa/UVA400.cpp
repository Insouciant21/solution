#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<string> p;
        string t;
        int m = 0;
        while (n--) {
            cin >> t;
            p.push_back(t);
            m = max(m, int(t.length()));
        }
        sort(p.begin(), p.end());
        int c = 62 / (m + 2);
        int r = int(p.size() - 1) / c + 1;
        cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < r; i++) {
            for (int j = i; j < p.size() && (j - i) / r <= c; j += r) {
                if ((j - i) / r != c) cout << left << setw(m + 2) << p[j];
                else cout << left << setw(m) << p[j];
            }
            cout << endl;
        }
    }
    return 0;
}

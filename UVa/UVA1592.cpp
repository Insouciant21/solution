#include <bits/stdc++.h>

using namespace std;

map<string, int> table;
map<pair<int, int>, int> ID;

int main() {
    int n, m;
    while (cin >> n >> m) {
        table.clear();
        ID.clear();
        int id = 0;
        getchar();
        for (int i = 0; i < n; i++) {
            string t;
            getline(cin, t);
            stringstream ss(t);
            for (int j = 0; j < m; j++) {
                getline(ss, t, ',');
                if (table.count(t)) ID[{i, j}] = table[t];
                else ID[{i, j}] = table[t] = id++;
            }
        }
        bool found = false;
        for (int c1 = 0; c1 < m && !found; c1++) {
            for (int c2 = c1 + 1; c2 < m && !found; c2++) {
                map<pair<int, int>, int> p;
                for (int r = 0; r < n; r++) {
                    if (p.count({ID[{r, c1}], ID[{r, c2}]})) {
                        cout << "NO" << endl;
                        cout << p[{ID[{r, c1}], ID[{r, c2}]}] + 1 << " " << r + 1 << endl;
                        cout << c1 + 1 << " " << c2 + 1 << endl;
                        found = true;
                        break;
                    }
                    p[{ID[{r, c1}], ID[{r, c2}]}] = r;
                }
                p.clear();
            }
        }
        if (!found) cout << "YES" << endl;
    }
    return 0;
}

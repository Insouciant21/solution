#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int main() {
    int n, m;
    int k;
    vector<int> a[maxn];
    int p[maxn];
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            cin >> t;
            a[t].push_back(i);
        }
        p[i] = 1;
    }
    for (int i = 1; i <= k; i++) {
        set<int> s;
        for (int j = 0; j < a[i].size(); j++) s.insert(p[a[i][j]]++);
        cout << s.size() << " ";
    }
}

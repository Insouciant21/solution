/*
  Problem: P2548
  Time: 2021/6/7 11:14
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    cin >> m >> n;
    vector<string> p1(m), p2(m);
    vector<string> ans(m);
    vector<bool> g(m);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            string k;
            cin >> k;
            p2[j] = k;
        }
        if (i == 1)
            p1 = p2;
        for (int j = 0; j < m; j++) {
            if (g[j])
                continue;
            if (p1[j] != p2[j]) {
                ans[j] = '*';
                g[j] = 1;
            }
        }
        p1 = p2;
    }
    for (int i = 0; i < m; i++) {
        if (ans[i].empty())
            ans[i] = p1[i];
    }
    for (auto &i : ans)
        cout << i << ' ';
    return 0;
}

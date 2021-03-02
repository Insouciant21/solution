/*
  Problem: P1088
  Time: 2020/12/26 09:25:06
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> p;
    int n, m;
    cin >> n >> m;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        p.push_back(t);
    }
    for (int i = 0; i < m; i++)
        next_permutation(p.begin(), p.end());
    for_each(p.begin(), p.end(), [](int x) { cout << x << " "; });
    return 0;
}
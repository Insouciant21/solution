/*
  Problem: P1571
  Time: 2021/7/7 12:19
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> a, b;
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        a.push_back(p);
    }
    for (int i = 0; i < m; i++) {
        int p;
        scanf("%d", &p);
        b.push_back(p);
    }
    sort(b.begin(), b.end());
    for (auto &i : a) {
        if (binary_search(b.begin(), b.end(), i))
            printf("%d ", i);
    }
    return 0;
}

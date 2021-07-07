/*
  Problem: P1102
  Time: 2021/7/7 13:24
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, c;
    long long ans = 0;
    scanf("%d %d", &n, &c);
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        p.push_back(t);
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        long long g = p[i] + c;
        if (binary_search(p.begin(), p.end(), g)) {
            ans += upper_bound(p.begin(), p.end(), g) - lower_bound(p.begin(), p.end(), g);
            // printf("%d-%d=%d\n", g, p[i], c);
        }
    }
    printf("%lld", ans);
    return 0;
}

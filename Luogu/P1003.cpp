/*
  Problem: P1003
  Time: 2021/5/22 20:37
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, ans = -1;

struct rect {
    int a, b;
    int g, k;
} r[10001];

int x, y;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> r[i].a >> r[i].b >> r[i].g >> r[i].k;
    cin >> x >> y;
    for (int i = 1; i <= n; i++) {
        if (r[i].a + r[i].g >= x && r[i].b + r[i].k >= y && x >= r[i].a && y >= r[i].b)
            ans = i;
    }
    cout << ans << endl;
    return 0;
}

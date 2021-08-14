/*
  Problem: P1105
  Time: 2021/7/5 17:29
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Platform {
    int h, l, r;
    int id;
    int a1, a2;
} p[1001];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].h >> p[i].l >> p[i].r;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n, [](Platform a, Platform b) {
        if (a.h != b.h) return a.h > b.h;
        return a.id < b.id;
    });
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (p[i].l > p[j].l && p[i].l < p[j].r) {
                p[i].a1 = p[j].id;
                break;
            }
        }
        for (int j = i + 1; j <= n; j++) {
            if (p[i].r > p[j].l && p[i].r < p[j].r) {
                p[i].a2 = p[j].id;
                break;
            }
        }
    }
    sort(p + 1, p + 1 + n, [](Platform a, Platform b) { return a.id < b.id; });
    for (int i = 1; i <= n; i++) {
        cout << p[i].a1 << " " << p[i].a2 << endl;
    }
    return 0;
}

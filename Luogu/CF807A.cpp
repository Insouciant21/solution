/*
  Problem: CF807A
  Time: 2020/10/02 09:17:33
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int pst;
    int prs;
} f[1010], p[1010];

int n;

int main() {
    scanf("%d", &n);
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &f[i].pst, &f[i].prs);
        p[i] = f[i];
        if (f[i].pst != f[i].prs) {
            ok = true;
        }
    }
    if (ok) {
        puts("rated");
        return 0;
    }
    sort(f + 1, f + 1 + n, [](Node x, Node y) { return x.pst > y.pst; });
    for (int i = 1; i <= n; i++) {
        if (p[i].pst != f[i].pst || p[i].prs != f[i].prs) {
            puts("unrated");
            return 0;
        }
    }
    puts("maybe");
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct tri {
    int a, b, c;
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<tri> a;
    for (int i = 0, t1, t2, t3; i < n - 2; i++) {
        cin >> t1 >> t2 >> t3;
        a.push_back({t1, t2, t3});
    }
    tri &p = a[0];
    int x = 0;
    x += (p.a == p.b + 1 || p.a == p.b - 1 || (p.a == 0 && p.b == n - 1));
    x += (p.a == p.c + 1 || p.a == p.c - 1 || (p.a == 0 && p.c == n - 1));
    x += (p.b == p.c + 1 || p.b == p.c - 1 || (p.b == 0 && p.c == n - 1));
    if (x == 2) cout << "JMcat Win\n";
    if (x == 1) cout << ((n - 5) % 2 == 0 ? "PZ Win\n" : "JMcat Win\n");
    if (x == 0) cout << ((n - 6) % 2 == 1 ? "PZ Win\n" : "JMcat Win\n");
    return 0;
}
// Insouciant at 20:41
// Status: AC
// Problem: 3644

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e5) + 1;

int fa[maxn];
int findfa(int x) {
    return (fa[x] == x) ? x : fa[x] = findfa(fa[x]);
}

int main() {
    freopen("temp.in", "r", stdin);
    int a, b;
    while (cin >> a) {
        for (int i = 0; i < maxn; i++) fa[i] = i;
        int ans = 0;
        while (a != -1) {
            cin >> b;
            a = findfa(a), b = findfa(b);
            if (a == b) ans++;
            else fa[a] = b;
            cin >> a;
        }
        cout << ans << endl;
    }
    return 0;
}
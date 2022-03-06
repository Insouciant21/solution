// Insouciant at 21:19
// Status: AC
// Problem: 3027.cpp

#include <bits/stdc++.h>

using namespace std;

const int maxn = 20100;

pair<int, int> fa[maxn];

int find(int u) {
    if (fa[u].first == u) return u;
    int root = find(fa[u].first);
    fa[u].second += fa[fa[u].first].second;
    fa[u].first = root;
    return fa[u].first;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(fa, 0, sizeof fa);
        int n;
        cin >> n;
        for (int i = 0; i < maxn; i++) fa[i] = {i, 0};
        string f;
        while (getline(cin, f)) {
            if (f[0] == 'O') break;
            if (f[0] == 'E') {
                int k;
                sscanf(f.c_str(), "E %d", &k);
                find(k);
                printf("%d\n", fa[k].second);
            }
            else if (f[0] == 'I') {
                int u, v;
                sscanf(f.c_str(), "I %d %d", &u, &v);
                fa[u].first = v;
                fa[u].second = abs(u - v) % 1000;

            }
        }
    }
    return 0;
}

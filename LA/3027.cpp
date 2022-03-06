// Insouciant at 21:19
// Status:
// Problem: 3027.cpp

#include <bits/stdc++.h>

using namespace std;

const int maxn = 20100;

pair<int, int> fa[maxn];

// pair<int,int> operator=(pair<int,int>a,pair<int,int)

int updateDist(int u) {
    if (fa[u].first == u) return u;
    else {
        fa[u].first = updateDist(u);
        fa[u].second += fa[fa[u].first].second;
        return fa[u].first;
    }
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
            if (f == "O") break;
            if (f == "E") {
                int k;
                sscanf(f.c_str(), "E %d", &k);
                printf("%d\n", fa[k].second);
            }
            else if (f == "I") {
                int u, v;
                sscanf(f.c_str(), "I %d %d", &u, &v);
                fa[u] = {v, abs(u - v) % 1000};
                updateDist(u);
            }
        }
    }
    return 0;
}

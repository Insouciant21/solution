#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

struct Item {
    int v, w;
    int u;
};
int f[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, V;
    cin >> n >> V;
    vector<Item> a;
    for (int i = 1, v, w, s, c = 1; i <= n; i++, c = 1) {
        cin >> v >> w >> s;
        if (s > 0) {
            while (s - c >= 0) {
                a.push_back({c * v, c * w, 0});
                s -= c, c <<= 1;
            }
            a.push_back({v * s, w * s, 0});
        }
        else a.push_back({v, w, s == -1 ? 0 : 1});
    }
    for (auto &i : a) {
        if (!i.u)
            for (int j = V; j >= i.v; j--) f[j] = max(f[j], f[j - i.v] + i.w);
        else
            for (int j = i.v; j <= V; j++) f[j] = max(f[j], f[j - i.v] + i.w);
    }
    cout << f[V] << endl;
    return 0;
}
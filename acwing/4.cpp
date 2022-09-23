#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

struct Item {
    int v, w;
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
    for (int i = 1, v, w, s; i <= n; i++) {
        cin >> v >> w >> s;
        while (s--) a.push_back({v, w});
    }
    for (auto & i : a) {
        for (int j = V; j >= i.v; j--) f[j] = max(f[j], f[j - i.v] + i.w);
    }
    cout << f[V] << endl;
    return 0;
}
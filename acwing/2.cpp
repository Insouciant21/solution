#include <bits/stdc++.h>

using namespace std;
const int maxn = 1010;
int v[maxn], w[maxn];
int f[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, V;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = V; j >= v[i]; j--) {
            f[j] = max(f[j - v[i]] + w[i], f[j]);
        }
    }
    cout << f[V] << endl;
    return 0;
}
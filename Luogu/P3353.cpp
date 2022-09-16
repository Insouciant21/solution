#include <bits/stdc++.h>

using namespace std;

const int maxx = 100010;

int x[maxx];
int sum[maxx];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, w;
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        x[a] += b;
    }
    int ans = 0;
    for (int i = 1; i < maxx; i++) sum[i] = sum[i - 1] + x[i];
    for (int i = 1; i < maxx; i++) ans = max(ans, sum[i] - sum[max(i - w, 0)]);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 100, maxq = 30;
int d[maxn];
int f[maxn];
int n, q;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    cin >> q;
    for (int b = 1, k; b <= q; b++) {
        deque<int> p;
        cin >> k;
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            while (!p.empty() && i - p.front() > k) p.pop_front();
            while (!p.empty() && ((f[p.back()] > f[i - 1]) || (f[p.back()] == f[i - 1] && d[i - 1] > d[p.back()])))
                p.pop_back();
            p.push_back(i - 1);
            if (i != 1 && d[i] >= d[p.front()]) f[i] = f[p.front()] + 1;
            else f[i] = f[p.front()];
        }
        cout << f[n] << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
int n, k;
long long e[maxn], sum[maxn], f[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
        sum[i] = sum[i - 1] + e[i];
    }
    deque<int> p;
    for (int i = 1; i <= n; i++) {
        while (!p.empty() && p.front() < i - k) p.pop_front();
        while (!p.empty() && f[p.back() - 1] - sum[p.back()] < f[i - 2] - sum[i - 1]) p.pop_back();
        p.push_back(i - 1);
        f[i] = f[p.front() - 1] + sum[i] - sum[p.front()];
    }
    cout << f[n] << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 50010;

int main() {
    int L, n, m;
    int a[maxn], d[maxn];
    cin >> L >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        d[i] = a[i] - (i == 0 ? 0 : a[i - 1]);
    }
    d[n] = L - a[n - 1];
    int l = 1, r = L;
    int mid;
    while (l < r) {
        for (int i = 0; i <= n; i++) a[i] = d[i];
        mid = (l + r + 1) >> 1;
        int cnt = 0;
        for (int i = 0; i <= n; i++)
            if (a[i] < mid) a[i + 1] = a[i + 1] + a[i], cnt++;
        if (cnt <= m) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}
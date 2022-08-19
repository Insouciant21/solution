#include <bits/stdc++.h>

using namespace std;

const int maxn = 500010;

int tmp[maxn], a[maxn];

long long ans = 0;

void merge(int l, int r) {
    if (r - l <= 1) return;
    int mid = l + ((r - l) >> 1);
    merge(l, mid), merge(mid, r);
    for (int i = l, j = mid, k = l; k < r; k++) {
        if (j == r || (i < mid && a[i] <= a[j])) tmp[k] = a[i++];
        else tmp[k] = a[j++], ans += (mid - i);
    }
    for (int i = l; i < r; i++) a[i] = tmp[i];
}

int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    merge(0, n);
    cout << ans << endl;
}
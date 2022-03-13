/*
 *  Problem: 4329.cpp
 *  Author: Insouciant21
 *  Date: 2022/3/13
 *  failed
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100011;
int c[maxn];
int x[maxn];

int lowbit(int f) {
    return f & (-f);
}

void add(int i, int v) {
    while (i <= 100000) {
        x[i] += v;
        i += lowbit(i);
    }
}

int sum(int i) {
    int sum = 0;
    while (i > 0) {
        sum += x[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    freopen("t.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a;
        a.resize(n);
        fill(x, x + maxn, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c[i] = sum(a[i]);
            add(a[i], 1);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) ans += c[i] * (n - i - sum(a[i]) + c[i]) + (i - c[i]) * (sum(a[i]) - c[i] - 1);
        cout << ans << endl;
    }
    return 0;
}

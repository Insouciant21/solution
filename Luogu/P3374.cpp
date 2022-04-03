/*
 *  Problem: P3374.cpp
 *  Author: Insouciant21
 *  Date: 2022/3/13
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 * int(1e5) + 10;
long long tree[maxn];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int index, long long val) {
    while (index <= n) {
        tree[index] += val;
        index += lowbit(index);
    }
}

long long sum(int index) {
    long long ret = 0;
    while (index) {
        ret += tree[index];
        index -= lowbit(index);
    }
    return ret;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        add(i, t);
    }
    while (m--) {
        int c, x, y;
        cin >> c >> x >> y;
        if (c == 1) add(x, y);
        if (c == 2) cout << sum(y) - sum(x - 1) << endl;
    }
    return 0;
}

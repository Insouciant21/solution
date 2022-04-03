/*
 *  Problem: P2357.cpp
 *  Author: Insouciant21
 *  Date: 2022/3/13
 *  failed
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * int(1e5) + 10;
int n, f;
long long a[maxn];
long long b[maxn];
long long ib[maxn];

int lowbit(int x) {
    return x & -x;
}

void add(int index, long long val) {
    long long g = index * val;
    while (index <= n) {
        b[index] += val, ib[index] +=g;
        index += lowbit(index);
    }
}

long long sum(int index, const long long *p) {
    long long s = 0;
    while (index) {
        s += p[index];
        index -= lowbit(index);
    }
    return s;
}

long long getSum(int index) {
    return sum(index, b) * (index + 1) - sum(index, ib);
}

int main() {
    cin >> n >> f;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    for (int i = 0; i < f; i++) {
        int c;
        cin >> c;
        int l, r, k;
        if (c == 1) {
            cin >> l >> r >> k;
            add(l, k);
            add(r + 1, -k);
        }
        if (c == 2 || c == 3) {
            cin >> k;
            k = (c == 2) ? k : -k;
            a[1] += k;
            add(1, k);
        }
        if (c == 4) {
            cin >> l >> r;
            printf("%lld\n", getSum(r) - getSum(l - 1));
        }
        if (c == 5) printf("%lld\n", a[1]);
    }

    return 0;
}

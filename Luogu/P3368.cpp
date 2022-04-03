/*
 *  Problem: P3368.cpp
 *  Author: Insouciant21
 *  Date: 2022/3/13
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 * int(1e5) + 10;
long long tree1[maxn];
// long long tree2[maxn];
long long a[maxn];
int n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int index, long long val) {
    // int g = index;
    while (index <= n) {
        tree1[index] += val; //, tree2[index] += g * val;
        index += lowbit(index);
    }
}
void adds(int l, int r, int k) {
    add(l, k);
    add(r + 1, -k);
}

long long sum(int index, const long long *t) {
    long long ret = 0;
    while (index) {
        ret += t[index];
        index -= lowbit(index);
    }
    return ret;
}

long long getSum(int index) {
    return sum(index, tree1);
}

int main() {
    cin >> n >> m;
    memset(a, 0, sizeof a);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while (m--) {
        int c, x, y;
        cin >> c >> x;
        if (c == 1) {
            int k;
            cin >> y >> k;
            adds(x, y, k);
        }
        if (c == 2) cout << getSum(x) << endl;
    }
    return 0;
}

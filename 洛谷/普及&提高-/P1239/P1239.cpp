/*
 *  Problem: P1239
 *  Author: Insouciant21
 *  Time: 2020/9/5 16:03:52
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    ios::sync_with_stdio(0);
    cin >> n;
    long long cnt[10] = { 0 };
    for (int i = 1; i <= n; i++) {
        int p = i;
        while (p > 0) {
            cnt[p % 10]++;
            p /= 10;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << endl;
    }
    return 0;
}

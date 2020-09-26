/*
  Problem: P1865
  Time: 2020/09/26 11:36:37
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxm = int(1e6) + 10;
int t, m;
bitset<maxm> numlist;

void prework() {
    numlist[0] = numlist[1] = 1;
    numlist[2] = 0;
    for (int i = 2; i <= maxm; i++)
        if (!numlist[i])
            for (int j = 2; i * j <= maxm; j++) numlist[i * j] = 1;
    return;
}

int main() {
    prework();
    ios::sync_with_stdio(false);
    cin >> t >> m;
    for (int i = 1; i <= t; i++) {
        int l, r;
        cin >> l >> r;
        if (l < 1 || r > m) {
            cout << "Crossing the line" << endl;
            continue;
        }
        int ans = 0;
        for (int i = l; i <= r; i++)
            if (!numlist[i])
                ans++;
        cout << ans << endl;
    }
    return 0;
}
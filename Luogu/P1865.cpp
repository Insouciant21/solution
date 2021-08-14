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
bitset<maxm> numList;

void preWork() {
    numList[0] = numList[1] = 1;
    numList[2] = 0;
    for (int i = 2; i <= maxm; i++)
        if (!numList[i])
            for (int j = 2; i * j <= maxm; j++)
                numList[i * j] = 1;
    return;
}

int main() {
    preWork();
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
            if (!numList[i]) ans++;
        cout << ans << endl;
    }
    return 0;
}
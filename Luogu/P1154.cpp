/*
 *  Problem: P1154
 *  Author: Insouciant21
 *  Time: 2020/9/5 12:41:04
 *  Status: AC
 */

#include <bits/stdc++.h>

using namespace std;
int n;
int s[1000001];
bitset<1000001> mod;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            mod[abs(s[i] - s[j])] = 1;
    }
    for (int i = n;; i++) {
        if (mod[i] != 1) {
            cout << i << endl;
            return 0;
        }
    }
}

/*
 *  Problem: P4994
 *  Author: Insouciant21
 *  Time: 2020/9/11 18:08:43
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    int x = 0, y = 1;
    int z = 0;
    int m;
    cin >> m;
    for (int i = 0;; i++) {
        x %= m, y %= m;
        if (i != 0 && x == 0 && y == 1) {
            cout << i << endl;
            return 0;
        }
        swap(x, y);
        y = y + x;
    }
    return 0;
}

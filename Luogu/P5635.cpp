//
//  Problem: P5635
//  Time: 2020/09/25 21:32:31
//  Author: Insouciant21
//  Status: Accepted
//

#include <bits/stdc++.h>

using namespace std;

int x, y, mod;
short mem[10010][10010];

int search(int x, int y) {
    if (mem[x][y] == -1) return 3;
    mem[x][y] = -1;
    if (x == 0) return mem[x][y] = 1;
    if (y == 0) return mem[x][y] = 2;
    int res = (x + y) % mod;
    return mem[x][y] = search(res, (res + y) % mod);
}

int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T >> mod;
    for (int i = 1; i <= T; i++) {
        cin >> x >> y;
        int ans = search(x, y);
        if (ans == 3)
            cout << "error" << endl;
        else if (ans == 2)
            cout << 2 << endl;
        else if (ans == 1)
            cout << 1 << endl;
    }
    return 0;
}
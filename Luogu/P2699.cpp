/*
  Problem: P2699
  Time: 2020/09/26 17:29:49
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long l, r, w;
long long res = 1;
bool found = false;
const long long maxll = numeric_limits<long long>::max();

int main() {
    ios::sync_with_stdio(false);
    cin >> l >> r >> w;
    long long limit = maxll / w;
    if (w == 1) return cout << (l == 1 && r >= 1) ? "1" : "-1", 0;
    while (true) {
        if (res >= l && res <= r) {
            cout << res << " ";
            found = true;
        }
        if (res > r / w) break;
        res *= w;
    }
    if (!found) cout << "-1" << endl;
    return 0;
}
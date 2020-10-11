/*
  Problem: P6850
  Time: 2020/10/11 13:38:02
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, e, f, g, h, i;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
    int res = a + 50 + b + c + d + e + f + g;
    if (h)
        res += 5;
    if (res >= i)
        cout << "AKIOI" << endl;
    else
        cout << "AFO" << endl;
    return 0;
}
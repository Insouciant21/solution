/*
  Problem: P2026
  Time: 2021/5/20 22:23
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

struct frac {
    int up, down;
    void simplify() {
        int g = gcd(up, down);
        up /= g;
        down /= g;
        if (down < 0)
            down = -down, up = -up;
    }
};

int main() {
    int x1, x2;
    int y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    frac k {};
    k.up = y1 - y2;
    k.down = x1 - x2;
    k.simplify();
    frac b {};
    b.up = y1 * k.down - x1 * k.up;
    b.down = k.down;
    b.simplify();
    cout << "y=";
    if (k.down == 1)
        cout << k.up << "x";
    else
        cout << k.up << "/" << k.down << "*x";
    if (b.up > 0) {
        cout << "+" << b.up;
        if (b.down != 1)
            cout << "/" << b.down;
    }
    if (b.up < 0) {
        cout << b.up;
        if (b.down != 1)
            cout << "/" << b.down;
    }
    return 0;
}

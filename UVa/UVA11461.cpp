/*
 *  Problem: UVA11461.cpp
 *  Author: Insouciant21
 *  Date: 2022/4/14
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.out","w",stdout);
#endif
    int a, b;
    while (cin >> a >> b) {
        if (a == b && b == 0) break;
        int l = ceil(sqrt(a)), r = floor(sqrt(b));
        cout << r - l + 1 << endl;
    }
    return 0;
}

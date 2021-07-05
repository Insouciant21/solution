/*
  Problem: B2006
  Time: 2021/7/5 18:32
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    double x, a, b, y;
    cin >> x >> a >> y >> b;
    double z = (b * y - a * x) / (b - a);
    cout << fixed << setprecision(2) << z << endl;
    return 0;
}

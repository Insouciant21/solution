/*
  Problem: 1007
  Time: 2021/5/22 19:24
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    int k = a / b;
    double r = a - b * k;
    cout << fixed << setprecision(2) << r << endl;
    return 0;
}

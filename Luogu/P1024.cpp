/*
  Problem: P1024
  Time: 2021/5/24 22:42
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;

double f(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    int cnt = 0;
    cin >> a >> b >> c >> d;
    for (double i = -100.0; i <= 100.0; i = i + 0.001) {
        double l = i, r = i + 0.001;
        if (f(l) * f(r) < 0) {
            cout << fixed << setprecision(2) << l << " ";
            cnt++;
        }
        if (cnt == 3) break;
    }
    return 0;
}

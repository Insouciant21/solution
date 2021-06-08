/*
  Problem: P4710
  Time: 2021/6/8 12:36
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

double v, z;

int main() {
    cin >> v >> z;
    double vx = v * sin(z), vy = v * cos(z);
    double t = vx * cos(z) / sin(z) / 10;
    printf("%.15lf %.15lf", vx * t, 5 * t * t);
    return 0;
}

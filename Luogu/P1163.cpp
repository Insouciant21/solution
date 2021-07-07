/*
  Problem: P1163
  Time: 2021/7/7 11:38
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    double l, r, mid;
    l = 0;
    r = 5;
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    while (true) {
        mid = (l + r) / 2;
        double money = 0;
        double p = 1.0;
        for (int i = 1; i <= n; i++) {
            p *= (1.0 + mid);
            money += b / p;
        }
        if (a + 0.0001 > money && a - 0.0001 < money)
            break;
        if (a + 0.0001 < money)
            l = mid;
        else
            r = mid;
    }
    printf("%.1lf", mid * 100);
    return 0;
}

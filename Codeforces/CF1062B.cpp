/*
  Problem: CF1062B
  Time: 2020/11/04 20:42:25
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 1;

void factor(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans *= i;
        }
    }
    if (n > 1) ans *= n;
}

int main() {
    scanf("%d", &n);
    factor(n);
    long long res = ans;
    int step = 0;
    while (res % n != 0) {
        res *= res;
        step++;
    }
    if (res > n) step++;
    printf("%d %d", ans, step);
    return 0;
}
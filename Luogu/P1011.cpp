/*
  Problem: P1011
  Time: 2021/5/22 17:48
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int f[24];
int a, n, m, x;

void fib() {
    f[1] = f[2] = 1;
    for (int i = 3; i < 24; i++)
        f[i] = f[i - 1] + f[i - 2];
}

int main() {
    fib();
    scanf("%d %d %d %d", &a, &n, &m, &x);
    if (n <= 3) {
        switch (n) {
            case 1:
            case 2:
                printf("%d", a);
                break;
            case 3:
                if (x != 3)
                    printf("%d", a);
                else
                    printf("0");
            default:
                break;
        }
        return 0;
    }
    if (n == x) {
        printf("0");
        return 0;
    }
    int b = (m - (f[n - 3] + 1) * a) / (f[n - 2] - 1);
    if (x < 3) {
        printf("%d", a);
        return 0;
    }
    int k = a;
    int up = b, down;
    for (int i = 3; i <= x; i++) {
        down = up;
        up = f[i - 2] * a + f[i - 1] * b;
        k = k + up - down;
    }
    printf("%d", k);
    return 0;
}

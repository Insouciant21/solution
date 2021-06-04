/*
  Problem: P1147
  Time: 2021/5/29 11:35
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    scanf("%d", &m);
    for (int i = m; i >= 2; i--) {
        if (i % 2 == 1 && m % i == 0) {
            int k = m / i;
            if (k - i / 2 >= 0)
                printf("%d %d\n", k - i / 2, k + i / 2);
        }
        if (i % 2 == 0 && m % i != 0 && m * 2 % i == 0) {
            int k = m / i;
            if (k - i / 2 + 1 >= 0)
                printf("%d %d\n", k - i / 2 + 1, k + i / 2);
        }
    }
    return 0;
}

/*
  Problem: CF870C
  Time: 2020/10/13 21:41:40
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int q, n;

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        int ans = 0;
        if (n % 2 != 0) n -= 9, ans = 1;
        ans += n / 4;
        if (n < 4 && n != 0) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
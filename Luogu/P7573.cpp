/*
  Problem: P7573
  Time: 2021/5/20 20:39
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        int n, ans;
        scanf("%d", &n);
        ans = (n + 1) / 2;
        if (n == 1)
            ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}

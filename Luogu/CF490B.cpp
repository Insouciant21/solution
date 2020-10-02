/*
  Problem: CF490B
  Time: 2020/10/02 20:45:17
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = int(1e6) + 10;

int n;
int f[maxn];
int usea[maxn];
int useb[maxn];
int ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        f[l] = r;
        usea[l]++, useb[r]++;
    }
    for (int i = 1; i <= int(1e6); i++) {
        if (usea[i] == 1 && useb[i] == 0)
            ans[1] = i;
        if (useb[i] == 1 && usea[i] == 0)
            ans[n] = i;
        if (ans[1] && ans[n])
            break;
    }
    for (int i = 2; i <= n; i++) ans[i] = f[ans[i - 2]];
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
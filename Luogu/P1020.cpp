#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 0;
    int h[100010];
    while (cin >> h[++n]) {}
    n--;
    int f[100100];
    int ans = 0;
    for (int i = n; i > 0; i--) {
        f[i] = 1;
        for (int j = i + 1; j <= n; j++)
            if (h[i] >= h[j]) f[i] = max(f[i], f[j] + 1);
        ans = max(f[i], ans);
    }
    printf("%d\n", ans);
    memset(f, 0, sizeof f);
    ans = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (h[i] > h[j]) f[i] = max(f[i], f[j] + 1);
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
}
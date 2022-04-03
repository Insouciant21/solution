#include <bits/stdc++.h>

using namespace std;

int n;
int h[121];
int dp1[131], dp2[141];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", h + i);
        dp1[i] = 1;
        dp2[i] = 1;
    }
    memset(dp1, 0, sizeof dp1);
    memset(dp2, 0, sizeof dp2);
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (h[j] < h[i]) dp1[i] = max(dp1[i], dp1[j] + 1);
    for (int i = n; i > 0; i--)
        for (int k = n; k > i; k--)
            if (h[i] > h[k]) dp2[i] = max(dp2[i], dp2[k] + 1);
    int ans = 0x1f1e33;
    for (int i = 1; i <= n; i++) {
        if (ans > n - dp1[i] - dp2[i]) {
            ans = n - dp1[i] - dp2[i];
        }
    }
    printf("%d\n", ans - 1);
}
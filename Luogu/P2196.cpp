#include <bits/stdc++.h>
using namespace std;

int dp[23];
vector<int> edge[23];
int num[23];
int p[23];

void print(int f) {
    if (p[f] != 0) print(p[f]);
    printf("%d ", f);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int k = 0;
            scanf("%d", &k);
            if (k) edge[j].push_back(i);
        }
    }
    dp[1] = num[1];
    int ans = 0, pos = 0;
    memset(p, 0, sizeof p);
    for (int i = 2; i <= n; i++) {
        for (int j : edge[i]) {
            if (dp[j] > dp[i]) {
                dp[i] = dp[j];
                p[i] = j;
            }
        }
        dp[i] += num[i];
        if (ans < dp[i]) ans = dp[i], pos = i;
    }
    for (int i = 1; i <= n; i++)
        ans = max(dp[i], ans);
    print(pos);
    printf("\n%d\n", ans);
}
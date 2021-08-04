#include <bits/stdc++.h>

using namespace std;

int a[4001], b[4001], c[4001], d[4001];
unordered_map<long long, long long> mp;
int n;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d %d", a + i, b + i, c + i, d + i);
        }
        mp.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                mp[a[i] + b[j]]++;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ans += mp[-(c[i] + d[j])];
            }
        }
        printf("%lld\n", ans);
        if (t)
            puts("");
    }
    return 0;
}
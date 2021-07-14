/*
  Problem: CF988C
  Time: 2020/10/11 09:52:28
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

map<long long, bool> q;
map<long long, pair<long long, long long>> p;
int a[2 * int(1e5) + 1];

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int n;
        long long sum = 0;
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) {
            scanf("%d", a + j);
            sum += a[j];
        }
        for (int j = 1; j <= n; j++) {
            if (q[sum - a[j]]) {
                puts("YES");
                printf("%lld %lld\n", p[sum - a[j]].first, p[sum - a[j]].second);
                printf("%d %d\n", i, j);
                return 0;
            }
        }
        for (int j = 1; j <= n; j++) {
            q[sum - a[j]] = true;
            p[sum - a[j]] = {i, j};
        }
    }
    cout << "NO" << endl;
    return 0;
}
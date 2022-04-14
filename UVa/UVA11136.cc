/*
 *  Problem: UVA11136
 *  Author: Insouciant21
 *  Date: 2022/4/14
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    while(true) {
        priority_queue<int> q1;
        priority_queue<int, deque<int>, greater<int>> q2;
        map<int, int> f;
        int n;
        scanf("%d", &n);
        if(n==0) break;
        long long ans = 0;
        while (n--) {
            int k;
            scanf("%d", &k);
            while (k--) {
                int t;
                scanf("%d", &t);
                q1.push(t);
                q2.push(t);
                f[t]++;
            }
            int l = 0;
            while (true) {
                l = q1.top();
                q1.pop();
                if (f[l]) break;
            }
            f[l]--;
            int r = 0;
            while (true) {
                r = q2.top();
                q2.pop();
                if (f[r]) break;
            }
            f[r]--;
            ans += abs(r - l);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

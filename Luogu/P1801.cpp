/*
 *  Problem: P1801
 *  Author: Insouciant21
 *  Time: 2020/9/20 10:36:15
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * int(1e5) + 5;

int n, m;
int a[maxn];

priority_queue<int, vector<int>, less<int>> q1;
priority_queue<int, vector<int>, greater<int>> q2;

int main() {
    int p = 1;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        for (int j = p; j <= t; j++) {
            q1.push(a[j]);
            if (q1.size() == i) {
                q2.push(q1.top());
                q1.pop();
            }
        }
        p = t + 1;
        printf("%d\n", q2.top());
        q1.push(q2.top());
        q2.pop();
    }
    return 0;
}

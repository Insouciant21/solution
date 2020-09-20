/*
 *  Problem: P1230
 *  Author: Insouciant21
 *  Time: 2020/9/12 13:12:34
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Work {
    int t;
    int m;
};

int m, n;

Work p[510];

bool operator<(Work a, Work b) { return a.m < b.m; }

bool cmp(Work a, Work b) { return a.t < b.t; }

priority_queue<Work> q;

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 1; i <= n; i++) cin >> p[i].t;
    for (int i = 1; i <= n; i++) cin >> p[i].m, m -= p[i].m;
    sort(p, p + n + 1, cmp);
    int pos = n;
    for (int i = n; i > 0; i--) {
        while (pos != 0 && p[pos].t >= i) q.push(p[pos--]);
        if (q.empty())
            continue;
        m += q.top().m;
        q.pop();
    }
    cout << m << endl;
    return 0;
}

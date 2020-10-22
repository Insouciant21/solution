/*
  Problem: UVA12100
  Time: 2020/10/18 20:32:26
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Task {
    int id;
    int priority;
};

bool operator<(Task a, Task b) {
    return a.priority < b.priority;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int n, m;
        queue<Task> q;
        priority_queue<Task> p;
        cin >> n >> m;
        for (int i = 0, t; i < n; i++) {
            cin >> t;
            q.push({i, t});
            p.push({i, t});
        }
        while (true) {
            Task prs = q.front();
            q.pop();
            if (prs.priority == p.top().priority) {
                p.pop();
                ans++;
                if (prs.id == m) {
                    cout << ans << endl;
                    break;
                }
            }
            else {
                q.push(prs);
            }
        }
    }
    return 0;
}
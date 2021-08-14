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
        for (int i = 0, f; i < n; i++) {
            cin >> f;
            q.push({i, f});
            p.push({i, f});
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
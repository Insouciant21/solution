#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 100;
int a[maxn], f[maxn];

struct cmp {
    bool operator()(int lhs, int rhs) { return f[lhs] < f[rhs]; }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    f[0] = 0;
    priority_queue<int, deque<int>, cmp> q;
    q.push(0);
    for (int i = 1; i <= n; i++) {
        queue<int> p;
        while (!q.empty() && (a[i] & a[q.top()]) == 0) {
            p.push(q.top());
            q.pop();
        }
        if (q.empty()) f[i] = 1;
        else f[i] = f[q.top()] + 1;
        while (!p.empty()) {
            q.push(p.front());
            p.pop();
        }
        q.push(i);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
    return 0;
}
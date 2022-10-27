#include <bits/stdc++.h>

using namespace std;

int map[510][510];
int d[510][510];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
struct Point {
    int x, y, d;
    void move(int dxx) { x += dx[dxx], y += dy[dxx]; }
    Point(int a = 0, int b = 0, int c = 0) : x(a), y(b), d(c) {};
};
struct cmp {
    bool operator()(Point &lhs, Point &rhs) { return lhs.d < rhs.d; }
};
bool vis[510][510];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    queue<Point> q;
    Point s, e;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '+') q.push({i, j}), vis[i][j] = true;
            if (c == 'V') s = Point(i, j);
            if (c == 'J') e = Point(i, j);
        }
    }
    while (!q.empty()) {
        auto prs = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point ftr = prs;
            ftr.move(i), ftr.d++;
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (vis[ftr.x][ftr.y]) continue;
            vis[ftr.x][ftr.y] = true;
            d[ftr.x][ftr.y] = ftr.d;
            q.push(ftr);
        }
    }
    memset(vis, 0, sizeof vis);
    s.d = d[s.x][s.y];
    priority_queue<Point, vector<Point>, cmp> pq;
    pq.push(s);
    int ans = -1;
    vis[s.x][s.y] = true;
    while (!pq.empty()) {
        auto prs = pq.top();
        pq.pop();
        if (prs.x == e.x && prs.y == e.y) {
            ans = max(ans, prs.d);
            continue;
        }
        for (int i = 0; i < 4; i++) {
            Point ftr = prs;
            ftr.move(i);
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (vis[ftr.x][ftr.y]) continue;
            vis[ftr.x][ftr.y] = true;
            ftr.d = min(d[ftr.x][ftr.y], ftr.d);
            pq.push(ftr);
        }
    }
    cout << ans << endl;
    return 0;
}
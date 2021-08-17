#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int step;
};

queue<Point> q;
Point d[4] {-1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1, 0};

bool maze[510][510];
bool vis[510][510];

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    Point start {}, end {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            if (x == '#') maze[i][j] = true;
            if (x == 's') start.x = i, start.y = j, start.step = 0;
            if (x == 'g') end.x = i, end.y = j, end.step = 0;
        }
    }
    q.push(start);
    vis[start.x][start.y] = true;
    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        if (now.x == end.x && now.y == end.y) {
            cout << "Yes" << endl;
            return 0;
        }
        for (auto &i : d) {
            Point p = now;
            p.x += i.x, p.y += i.y, p.step++;
            if (p.x < 1 || p.y < 1 || p.x > n || p.y > m) continue;
            if (maze[p.x][p.y]) continue;
            if (vis[p.x][p.y]) continue;
            vis[p.x][p.y] = true;
            q.push(p);
        }
    }
    cout << "No" << endl;
    return 0;
}

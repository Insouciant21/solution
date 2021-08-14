#include <bits/stdc++.h>

using namespace std;

int n, m, k, ans;
bool mp[22][22];
int vis[22][22];
bool visX[22][22];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

struct Point {
    int x {}, y {};
    int ob {}, step {};
    explicit Point(int _x = 1, int _y = 1, int _ob = k, int _s = 0) : x(_x), y(_y), ob(_ob), step(_s) {}
    void move(int mode) { x += dx[mode], y += dy[mode], step++; }
};

void init();
void bfs();

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d", &n, &m);
        scanf("%d", &k);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) scanf("%d", &mp[i][j]);
        bfs();
        printf("%d\n", ans);
    }
    return 0;
}

void init() {
    ans = -1;
    memset(mp, 0, sizeof mp);
    memset(vis, 0, sizeof vis);
    memset(visX, 0, sizeof visX);
}

void bfs() {
    queue<Point> q;
    q.push(Point());
    visX[1][1] = true;
    while (!q.empty()) {
        Point u = q.front();
        q.pop();
        if (u.x == n && u.y == m) {
            ans = u.step;
            return;
        }
        for (int i = 0; i < 4; i++) {
            Point v = u;
            v.move(i);
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
            if (mp[v.x][v.y]) {
                if (v.ob) {
                    v.ob--;
                    if (vis[v.x][v.y] > v.ob) continue;
                    vis[v.x][v.y] = v.ob;
                    q.push(v);
                }
                continue;
            }
            if (visX[v.x][v.y]) continue;
            if (!mp[v.x][v.y]) v.ob = k;
            visX[v.x][v.y] = true;
            q.push(v);
        }
    }
}

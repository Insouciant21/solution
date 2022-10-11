#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    queue<Point> q;
    int vis[21][21];
    memset(vis, 0, sizeof vis);
    q.push({0, 0});
    if (x - 2 >= 0) {
        if (y - 1 >= 0) vis[x - 2][y - 1] = 1;
        if (y + 1 <= n) vis[x - 2][y + 1] = 1;
    }
    if (x + 2 <= n) {
        if (y - 1 >= 0) vis[x + 2][y - 1] = 1;
        if (y + 1 <= m) vis[x + 2][y + 1] = 1;
    }
    if (x - 1 >= 0) {
        if (y - 2 >= 0) vis[x - 1][y - 2] = 1;
        if (y + 2 <= m) vis[x - 1][y + 2] = 1;
    }
    if (x + 1 <= n) {
        if (y - 2 >= 0) vis[x + 1][y - 2] = 1;
        if (y + 2 <= m) vis[x + 1][y + 2] = 1;
    }
    vis[x][y] = vis[0][0] = 1;
    long long f[21][21];
    memset(f, 0, sizeof f);
    int dx[] = {1, 0}, dy[] = {0, 1};
    f[0][0] = 1;
    while (!q.empty()) {
        Point prs = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            Point r = prs;
            r.x += dx[i], r.y += dy[i];
            if (r.x > n || r.y > m) continue;
            if (vis[r.x][r.y] == 1) continue;
            if (vis[r.x][r.y] == -1) {
                f[r.x][r.y] += f[prs.x][prs.y];
                continue;
            }
            f[r.x][r.y] += f[prs.x][prs.y];
            vis[r.x][r.y] = -1;
            q.push(r);
        }
        /*
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) cout << f[i][j] << " ";
            cout << endl;
        }
        cout << endl;
         */
    }
    cout << f[n][m] << endl;
    return 0;
}
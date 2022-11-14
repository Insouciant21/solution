#include <bits/stdc++.h>

using namespace std;

const int maxn = 53;
int n, m;
struct Wall {
    int d[4];
} g[maxn][maxn];
struct Point {
    int x, y;
};

int fx[maxn][maxn][4];
int vis[maxn][maxn];
int cnt = 0;
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void floodfill() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;
            cnt++;
            vis[i][j] = cnt;
            queue<Point> q;
            q.push({i, j});
            while (!q.empty()) {
                auto r = q.front();
                q.pop();
                for (int movement = 0; movement < 4; movement++) {
                    Point v = r;
                    if (g[r.x][r.y].d[movement]) {
                        fx[r.x][r.y][movement] = cnt;
                        continue;
                    }
                    v.x += dx[movement], v.y += dy[movement];
                    if (v.x > n || v.y > m || v.x < 1 || v.y < 1) continue;
                    if (vis[v.x][v.y]) continue;
                    vis[v.x][v.y] = cnt;
                    q.push(v);
                }
            }
        }
    }
}
int ans[5000];

struct Result {
    int x, y;
    int size;
};

void print(Result x, char d) {
    cout << x.size << endl;
    cout << x.x << " " << x.y << " " << d << endl;
}
int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, t; j <= m; j++) {
            cin >> t;
            auto &f = g[i][j];
            for (int k = 0; k < 4; k++) f.d[k] = (t >> k) & 1;
        }
    }
    floodfill();
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) ans[vis[i][j]]++;
    int res = 0;
    for (int i = 1; i <= cnt; i++) res = max(res, ans[i]);
    cout << res << endl;
    Result x = {0, 0, 0}, e = {0, 0, 0};
    for (int j = 1; j < m; j++) {
        for (int i = n; i >= 1; i--) {
            if (fx[i][j + 1][0] == fx[i][j][2]) continue;
            int resX = ans[fx[i][j][2]] + ans[fx[i][j + 1][0]];
            if (resX > x.size) x.x = i, x.y = j, x.size = resX;
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = n; i > 1; i--) {
            if (fx[i][j][1] == fx[i - 1][j][3]) continue;
            int resX = ans[fx[i][j][1]] + ans[fx[i - 1][j][3]];
            if (resX > e.size) e.x = i, e.y = j, e.size = resX;
        }
    }
    if (e.size > x.size) print(e, 'N');
    else if (e.size < x.size) print(x, 'E');
    else {
        if (e.y <= x.y) print(e, 'N');
        if (e.y > x.y) print(x, 'E');
    }
    return 0;
}

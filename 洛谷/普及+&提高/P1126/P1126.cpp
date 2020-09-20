/*
 *  Problem: P1126
 *  Author: Insouciant21
 *  Time: 2020/9/13 16:57:57
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Robot {
    int x, y;
    int face;
    int step;
};

bool room[55][55];
bool vis[55][55][4];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int turn[2][4] = { 3, 2, 0, 1, 2, 3, 1, 0 };

int n, m;

queue<Robot> q;
Robot r;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            bool x;
            cin >> x;
            if (x) {
                room[i][j] = room[i - 1][j - 1] = room[i - 1][j] = room[i][j - 1] = 1;
            }
        }
    }
    Robot start, end;
    char f;
    cin >> start.x >> start.y >> end.x >> end.y >> f;
    if (f == 'E')
        start.face = 1;
    else if (f == 'W')
        start.face = 0;
    else if (f == 'S')
        start.face = 3;
    else
        start.face = 2;
    start.step = 0;
    q.push(start);
    vis[start.x][start.y][start.face] = 1;
    while (q.size()) {
        r = q.front(), q.pop();
        if (r.x == end.x && r.y == end.y) {
            cout << r.step << endl;
            return 0;
        }
        Robot x = r;
        for (int j = 1; j <= 3; j++) {
            x.x += dx[x.face], x.y += dy[x.face];
            if (x.x < 1 || x.y < 1 || x.x >= n || x.y >= m || room[x.x][x.y])
                break;
            if (vis[x.x][x.y][x.face])
                continue;
            vis[x.x][x.y][x.face] = 1;
            x.step = r.step + 1;
            q.push(x);
        }
        x = r;
        x.step++;
        for (int i = 0; i <= 1; i++) {
            x.face = turn[i][r.face];
            if (!vis[x.x][x.y][x.face]) {
                vis[x.x][x.y][x.face] = 1;
                q.push(x);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

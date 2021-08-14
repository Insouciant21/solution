/*
 *  Problem: P3818
 *  Author: Insouciant21
 *  Time: 2020/9/17 19:14:42
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

constexpr int inf = 0x3f3f3f;

struct Node {
    int x, y;
    int med;
};

int h, w;
int d, r;

char maze[1010][1010];
int vis[1010][1010][2];

queue<Node> q;

Node mov[4] = {1, 0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0};

bool check(Node p) {
    return p.x >= 1 && p.y >= 1 && p.x <= h && p.y <= w && maze[p.x][p.y] == '.';
}

int main() {
    cin >> h >> w >> d >> r;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> maze[i][j];
    memset(vis, -1, sizeof(vis));
    q.push({1, 1, 0});
    vis[1][1][0] = 0;
    while (q.size() && vis[h][w][0] == -1 && vis[h][w][1] == -1) {
        int cnt = 0;
        Node n = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Node p = n;
            p.x += mov[i].x, p.y += mov[i].y;
            if (check(p) && vis[p.x][p.y][p.med] == -1) {
                q.push(p);
                vis[p.x][p.y][p.med] = vis[n.x][n.y][n.med] + 1;
            }
            p = n;
            p.x += d, p.y += r;
            if (check(p) && vis[p.x][p.y][1] == -1 && n.med == 0) {
                p.med = 1;
                q.push(p);
                vis[p.x][p.y][1] = vis[n.x][n.y][0] + 1;
            }
        }
    }
    if (vis[h][w][0] == -1 && vis[h][w][1] == -1)
        cout << -1 << endl;
    else {
        int ans = inf;
        for (int i = 0; i < 2; i++)
            if (vis[h][w][i] != -1 && vis[h][w][i] < ans) ans = vis[h][w][i];
        cout << ans << endl;
    }
    return 0;
}

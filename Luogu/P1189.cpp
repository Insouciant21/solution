/*
 *  Problem: P1189
 *  Author: Insouciant21
 *  Time: 2020/9/15 19:05:35
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int step;
};

queue<Point> q;
Point start;

Point run[4] {0, 1, 0, -1, 0, 0, 1, 0, 0, 0, -1, 0};

int maze[60][60];
int vis[60][60];

int r, c;
int n;

int pa[1010];

map<string, int> direction;

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c;
    direction["EAST"] = 0, direction["NORTH"] = 1, direction["SOUTH"] = 2, direction["WEST"] = 3;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char x;
            cin >> x;
            if (x == 'X') maze[i][j] = 1;
            if (x == '*') start.x = i, start.y = j, start.step = 1;
        }
    }
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        pa[i] = direction[t];
    }
    vis[start.x][start.y] = 0;
    q.push(start);
    while (q.size()) {
        Point now = q.front();
        q.pop();
        if (now.step == n + 1) {
            maze[now.x][now.y] = -1;
        }
        Point p = now;
        p.step = now.step + 1;
        while (true) {
            p.x += run[pa[now.step]].x;
            p.y += run[pa[now.step]].y;
            if (p.x < 1 || p.y < 1 || p.x > r || p.y > c) break;
            if (vis[p.x][p.y] == p.step) continue;
            if (maze[p.x][p.y] == 1) break;
            vis[p.x][p.y] = p.step;
            q.push(p);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (maze[i][j] == -1) cout << "*";
            if (maze[i][j] == 1) cout << "X";
            if (maze[i][j] == 0) cout << ".";
        }
        cout << endl;
    }
    return 0;
}
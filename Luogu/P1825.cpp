/*
 *  Problem: P1825
 *  Author: Insouciant21
 *  Time: 2020/9/16 19:57:22
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

char maze[310][310];
bool vis[310][310];

int n, m;

Node st, ed;
queue<Node> q;

Node mov[4] {0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};

void teleport(Node &p) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == maze[p.x][p.y] && (i != p.x || j != p.y)) {
                p.x = i, p.y = j;
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            maze[i][j] = x;
            if (x == '@')
                st.x = i, st.y = j, st.step = 0;
            if (x == '=')
                ed.x = i, ed.y = j, ed.step = 0;
        }
    }
    q.push(st);
    vis[st.x][st.y] = 1;
    while (q.size()) {
        Node now = q.front();
        q.pop();
        if (now.x == ed.x && now.y == ed.y) {
            cout << now.step << endl;
            return 0;
        }
        if (maze[now.x][now.y] >= 'A' && maze[now.x][now.y] <= 'Z')
            teleport(now);
        for (int i = 0; i < 4; i++) {
            Node p = now;
            p.x += mov[i].x, p.y += mov[i].y, p.step++;
            if (p.x < 1 || p.y < 1 || p.x > n || p.y > m)
                continue;
            if (vis[p.x][p.y])
                continue;
            if (maze[p.x][p.y] == '#')
                continue;
            vis[p.x][p.y] = 1;
            q.push(p);
        }
    }
    return 0;
}

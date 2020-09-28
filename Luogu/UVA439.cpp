/*
 *  Problem: UVA439
 *  Author: Insouciant21
 *  Time: 2020/9/15 20:29:24
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

queue<Node> q;
Node mov[8] {-1, -2, 0, -1, 2, 0, 1, -2, 0, 1, 2, 0, 2, -1, 0, 2, 1, 0, -2, -1, 0, -2, 1, 0};

bool vis[9][9];

map<char, int> p;

void bfs(Node start, Node end) {
    while (q.size()) q.pop();
    memset(vis, 0, sizeof(vis));
    q.push(start);
    vis[start.x][start.y] = 1;
    while (q.size()) {
        Node now = q.front();
        q.pop();
        if (now.x == end.x && now.y == end.y) {
            printf("To get from %c%d to %c%d takes %d knight moves.\n", start.x + 'a' - 1, start.y, end.x + 'a' - 1, end.y, now.step);
            return;
        }
        for (int i = 0; i < 8; i++) {
            Node p = now;
            p.x += mov[i].x, p.y += mov[i].y, p.step++;
            if (p.x < 1 || p.y < 1 || p.x > 8 || p.y > 8)
                continue;
            if (vis[p.x][p.y])
                continue;
            vis[p.x][p.y] = 1;
            q.push(p);
        }
    }
}

int main() {
    string sx, ex;
    p['a'] = 1, p['b'] = 2, p['c'] = 3, p['d'] = 4, p['e'] = 5, p['f'] = 6, p['g'] = 7, p['h'] = 8;
    while (cin >> sx && sx[0] != EOF) {
        cin >> ex;
        Node r, e;
        r.x = p[sx[0]], r.y = sx[1] - '0', r.step = 0;
        e.x = p[ex[0]], e.y = ex[1] - '0',e.step = 0;
        bfs(r, e);
    }
    return 0;
}

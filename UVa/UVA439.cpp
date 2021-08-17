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
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    q.push(start);
    vis[start.x][start.y] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.x == end.x && now.y == end.y) {
            printf("To get from %c%d to %c%d takes %d knight moves.\n",
                   start.x + 'a' - 1,
                   start.y,
                   end.x + 'a' - 1,
                   end.y,
                   now.step);
            return;
        }
        for (auto &i : mov) {
            Node f = now;
            f.x += i.x, f.y += i.y, f.step++;
            if (f.x < 1 || f.y < 1 || f.x > 8 || f.y > 8) continue;
            if (vis[f.x][f.y]) continue;
            vis[f.x][f.y] = 1;
            q.push(f);
        }
    }
}

int main() {
    string sx, ex;
    p['a'] = 1, p['b'] = 2, p['c'] = 3, p['d'] = 4, p['e'] = 5, p['f'] = 6, p['g'] = 7, p['h'] = 8;
    while (cin >> sx && sx[0] != EOF) {
        cin >> ex;
        Node r {}, e {};
        r.x = p[sx[0]], r.y = sx[1] - '0', r.step = 0;
        e.x = p[ex[0]], e.y = ex[1] - '0', e.step = 0;
        bfs(r, e);
    }
    return 0;
}

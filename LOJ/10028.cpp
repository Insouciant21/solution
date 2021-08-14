#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

queue<Node> q;
Node mov[8] {-1, -2, 0, -1, 2, 0, 1, -2, 0, 1, 2, 0, 2, -1, 0, 2, 1, 0, -2, -1, 0, -2, 1, 0};

bool vis[310][310];
int n, l;

void bfs(Node start, Node end) {
    while (!q.empty()) q.pop();
    memset(vis, 0, sizeof(vis));
    q.push(start);
    vis[start.x][start.y] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        if (now.x == end.x && now.y == end.y) {
            cout << now.step << endl;
            return;
        }
        for (auto &i : mov) {
            Node p = now;
            p.x += i.x, p.y += i.y, p.step++;
            if (p.x < 0 || p.y < 0 || p.x >= l || p.y >= l) continue;
            if (vis[p.x][p.y]) continue;
            vis[p.x][p.y] = true;
            q.push(p);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l;
        Node r {}, e {};
        cin >> r.x >> r.y;
        r.step = e.step = 0;
        cin >> e.x >> e.y;
        bfs(r, e);
    }
    return 0;
}
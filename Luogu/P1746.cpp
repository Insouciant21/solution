/*
 *  Problem: P1746
 *  Author: Insouciant21
 *  Time: 2020/9/11 20:34:43
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

Node mov[4] {1, 0, 0, 0, 1, 0, -1, 0, 0, 0, -1, 0};

queue<Node> q;

Node run;

bool vis[1010][1010];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char m;
            cin >> m;
            if (m == '1')
                vis[i][j] = true;
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    q.push({x1, y1, 0});
    while (q.size()) {
        run = q.front(), q.pop();
        if (run.x == x2 && run.y == y2) {
            cout << run.step << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            Node m = run;
            m.x += mov[i].x, m.y += mov[i].y, m.step++;
            if (m.x < 1 || m.y < 1 || m.x > n || m.y > n)
                continue;
            if (vis[m.x][m.y])
                continue;
            vis[m.x][m.y] = true;
            q.push(m);
        }
    }
    return 0;
}

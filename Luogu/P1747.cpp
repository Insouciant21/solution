/*
 *  Problem: P1747
 *  Author: Insouciant21
 *  Time: 2020/9/11 20:00:34
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

Node direction[12] {-1, -2, 0, -1, 2, 0, 1, -2, 0, 1,  2,  0, 2,  -1, 0, 2, 1,  0,
                    -2, -1, 0, -2, 1, 0, 2, 2,  0, -2, -2, 0, -2, 2,  0, 2, -2, 0};

queue<Node> q;

Node run;

bool vis[30][30];

int main() {
    int m, n;
    cin >> m >> n;
    q.push({m, n, 0});
    while (q.size()) {
        run = q.front(), q.pop();
        if (run.x == 1 && run.y == 1) {
            cout << run.step << endl;
            break;
        }
        for (int i = 0; i < 12; i++) {
            Node mover = run;
            mover.x += direction[i].x, mover.y += direction[i].y, mover.step++;
            if (mover.x < 1 || mover.y < 1 || mover.x > 20 || mover.y > 20) continue;
            if (vis[mover.x][mover.y]) continue;
            vis[mover.x][mover.y] = true;
            q.push(mover);
        }
    }
    memset(vis, 0, sizeof(vis));
    while (q.size())
        q.pop();
    cin >> m >> n;
    q.push({m, n, 0});
    while (q.size()) {
        run = q.front(), q.pop();
        if (run.x == 1 && run.y == 1) {
            cout << run.step << endl;
            break;
        }
        for (int i = 0; i < 12; i++) {
            Node mover = run;
            mover.x += direction[i].x, mover.y += direction[i].y, mover.step++;
            if (mover.x < 1 || mover.y < 1 || mover.x > 20 || mover.y > 20) continue;
            if (vis[mover.x][mover.y]) continue;
            vis[mover.x][mover.y] = true;
            q.push(mover);
        }
    }
    return 0;
}

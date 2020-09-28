/*
 *  Problem: P2895
 *  Author: Insouciant21
 *  Time: 2020/9/9 21:43:53
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

constexpr auto inf = 0x3f3f3f;

struct Node {
    int x, y;
    int step;
};

Node mov[5] {0, 0, 0, 0, -1, 0, 0, 1, 0, 1, 0, 0, -1, 0, 0};

queue<Node> q;
Node man;

int farm[310][310];
bool viewed[310][310];

int main() {
    int m;
    ios::sync_with_stdio(0);
    cin >> m;
    q.push({0, 0, 0});
    for (int i = 0; i < 310; i++)
        for (int j = 0; j < 310; j++) farm[i][j] = inf;
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        for (int j = 0; j < 5; j++) {
            int xm = x + mov[j].x, ym = y + mov[j].y;
            if (xm == -1 || ym == -1)
                continue;
            if (farm[xm][ym] == inf || farm[xm][ym] > t)
                farm[xm][ym] = t;
        }
    }
    viewed[0][0] = 1;
    q.push({0, 0, 0});
    while (!q.empty()) {
        man = q.front(), q.pop();
        if (farm[man.x][man.y] == inf) {
            cout << man.step << endl;
            return 0;
        }
        for (int i = 1; i <= 4; i++) {
            Node p;
            p.x = man.x + mov[i].x, p.y = man.y + mov[i].y, p.step = man.step + 1;
            if (p.x == -1 || p.y == -1)
                continue;
            if (p.step < farm[p.x][p.y] && !viewed[p.x][p.y]) {
                q.push(p);
                viewed[p.x][p.y] = 1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}

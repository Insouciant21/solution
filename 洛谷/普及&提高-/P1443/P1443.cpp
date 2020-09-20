/*
 *  Problem: P1443
 *  Author: Insouciant21
 *  Time: 2020/9/10 18:47:04
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

bool viewed[410][410];
int chess[410][410];

Node mov[8]{ -1, -2, 0, -1, 2, 0, 1, -2, 0, 1, 2, 0, 2, -1, 0, 2, 1, 0, -2, -1, 0, -2, 1, 0 };

queue<Node> q;
Node man;

int main() {
    int n, m;
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int start_x, start_y;
    cin >> start_x >> start_y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) chess[i][j] = -1;
    q.push({ start_x, start_y, 0 });
    chess[start_x][start_y] = 0;
    viewed[start_x][start_y] = 1;
    while (q.size()) {
        man = q.front(), q.pop();
        for (int i = 0; i < 8; i++) {
            Node p;
            p.x = man.x + mov[i].x, p.y = man.y + mov[i].y, p.step = man.step + 1;
            if (p.x < 1 || p.y < 1 || p.x > n || p.y > m)
                continue;
            if (!viewed[p.x][p.y]) {
                q.push(p);
                viewed[p.x][p.y] = 1;
                chess[p.x][p.y] = p.step;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << left << setw(5) << chess[i][j];
        }
        cout << endl;
    }
    return 0;
}

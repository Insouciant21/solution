/*
  Problem: P1162
  Time: 2021/6/4 22:33
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int mp[31][31];

int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y, bool mode) {
    queue<pair<int, int>> q;
    int stx = x, sty = y;
    int p = mp[x][y];
    if (!mode)
        mp[x][y] = 9;
    else
        mp[x][y] = 2;
    q.push({stx, sty});
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int gx = q.front().first + dx[i], gy = q.front().second + dy[i];
            if (gx < 1 || gy < 1 || gx > n || gy > n)
                continue;
            if (mp[gx][gy] == p) {
                if (!mode)
                    mp[gx][gy] = 9;
                else
                    mp[gx][gy] = 2;
                q.push({gx, gy});
            }
        }
        q.pop();
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> mp[i][j];
    for (int i = 1; i <= n; i++) {
        if (i == 1 || i == n) {
            for (int j = 1; j <= n; j++)
                if (mp[i][j] == 0)
                    bfs(i, j, false);
        }
        else {
            if (mp[i][0] == 0)
                bfs(i, 0, false);
            if (mp[i][n] == 0)
                bfs(i, n, false);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (mp[i][j] == 0) {
                bfs(i, j, true);
                break;
            }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (mp[i][j] == 9 ? 0 : mp[i][j]) << ' ';
        }
        cout << endl;
    }
    return 0;
}

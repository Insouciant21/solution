/*
 *  Problem: P3956
 *  Author: Insouciant21
 *  Time: 2020/9/10 19:28:39
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

constexpr auto inf = 0x3f3f3f;

int chess[110][110];
int best[110][110];
int movx[4] = {0, 1, 0, -1}, movy[4] = {1, 0, -1, 0};

int m, n;
int ans = inf;

void dfs(int x, int y, int color, bool magic, int coin) {
    if (x < 1 || y < 1 || x > m || y > m)
        return;
    if (coin >= best[x][y])
        return;
    best[x][y] = coin;
    if (x == m && y == m) {
        ans = min(ans, coin);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + movx[i], ny = y + movy[i];
        if (chess[nx][ny] != inf) {
            if (chess[nx][ny] == chess[x][y])
                dfs(nx, ny, color, 0, coin);
            else
                dfs(nx, ny, chess[nx][ny], 0, coin + 1);
        }
        else if (!magic) {
            chess[nx][ny] = color;
            dfs(nx, ny, color, 1, coin + 2);
            chess[nx][ny] = inf;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for (int i = 0; i < 110; i++)
        for (int j = 0; j < 110; j++) chess[i][j] = best[i][j] = inf;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        chess[x][y] = c;
    }
    dfs(1, 1, chess[1][1], 0, 0);
    if (ans != inf)
        cout << ans << endl;
    else
        cout << -1 << endl;
    return 0;
}

/*
  Problem: P1434
  Time: 2020/10/17 12:13:29
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    int step;
};

int mem[101][101];
int maze[101][101];
bool vis[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int r, c;
int ans = 1;

void dfs(Point prs) {
    for (int i = 0; i < 4; i++) {
        Point ftr = prs;
        ftr.x += dx[i], ftr.y += dy[i], ftr.step = prs.step + 1;
        if (ftr.x < 1 || ftr.y < 1 || ftr.x > r || ftr.y > c) continue;
        if (maze[ftr.x][ftr.y] >= maze[prs.x][prs.y]) continue;
        if (vis[ftr.x][ftr.y]) continue;
        if (mem[ftr.x][ftr.y] >= ftr.step) continue;
        vis[ftr.x][ftr.y] = 1;
        mem[ftr.x][ftr.y] = ftr.step;
        dfs(ftr);
        vis[ftr.x][ftr.y] = 0;
    }
}

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= r; j++) {
            dfs({i, j, 1});
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            ans = max(ans, mem[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

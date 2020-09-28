//
//  Problem: P1238
//  Time: 2020/09/25 20:55:25
//  Author: Insouciant21
//  Status: Accepted
//

#include <bits/stdc++.h>

using namespace std;

struct Position {
    int x, y;
};

bool mp[16][16];
bool vis[16][16];

Position st, ed;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
bool ok = false;

Position arr[int(1e7)];

int n, m;

void dfs(Position prs, int step) {
    if (prs.x == ed.x && prs.y == ed.y) {
        for (int i = 0; i < step - 1; i++) {
            printf("(%d,%d)->", arr[i].x, arr[i].y);
        }
        printf("(%d,%d)\n", arr[step - 1].x, arr[step - 1].y);
        ok = true;
        return;
    }
    for (int i = 0; i < 4; i++) {
        Position ftr = prs;
        ftr.x += dx[i], ftr.y += dy[i];
        if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m)
            continue;
        if (vis[ftr.x][ftr.y])
            continue;
        if (!mp[ftr.x][ftr.y])
            continue;
        vis[ftr.x][ftr.y] = 1;
        arr[step] = ftr;
        dfs(ftr, step + 1);
        vis[ftr.x][ftr.y] = 0;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> mp[i][j];
    cin >> st.x >> st.y;
    cin >> ed.x >> ed.y;
    arr[0] = st;
    vis[st.x][st.y] = 1;
    dfs(st, 1);
    if (!ok)
        cout << -1 << endl;
    return 0;
}
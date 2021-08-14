/*
  Problem: P2199
  Time: 2020/09/25 22:09:26
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Position {
    int x, y;
    int step;
};

int n, m;

int mp[5010][5010];
bool vis[5010][5010];

queue<Position> q;
Position st, ed;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int lx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ly[8] = {0, 1, -1, -1, 1, -1, 0, 1};

void operation() {
    mp[ed.x][ed.y] = 2;
    for (int i = 0; i < 8; i++) {
        Position ftr = ed;
        while (true) {
            ftr.x += lx[i], ftr.y += ly[i];
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) break;
            if (mp[ftr.x][ftr.y] == 1) break;
            mp[ftr.x][ftr.y] = 2;
        }
    }
}

void bfs() {
    while (q.size())
        q.pop();
    q.push(st);
    vis[st.x][st.y] = 1;
    while (q.size()) {
        Position prs = q.front();
        q.pop();
        if (mp[prs.x][prs.y] == 2) {
            cout << prs.step << endl;
            return;
        }
        for (int i = 0; i < 4; i++) {
            Position ftr = prs;
            ftr.x += dx[i], ftr.y += dy[i], ftr.step++;
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (mp[ftr.x][ftr.y] == 1) continue;
            if (vis[ftr.x][ftr.y]) continue;
            vis[ftr.x][ftr.y] = 1;
            q.push(ftr);
        }
    }
    cout << "Poor Harry" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            (x == 'X') ? mp[i][j] = 1 : mp[i][j] = 0;
        }
    }
    st.step = 0;
    while (true) {
        cin >> ed.x >> ed.y >> st.x >> st.y;
        if (st.x == 0 && st.y == 0 && ed.x == 0 && ed.y == 0) break;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (mp[i][j] == 2) mp[i][j] = 0;
        operation();
        bfs();
    }
    return 0;
}
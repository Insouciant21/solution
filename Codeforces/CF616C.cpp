/*
  Problem: CF616C
  Time: 2020/09/28 21:13:03
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

char maze[1010][1010];
int vis[1010][1010];
int ans[500010];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m;
int cnt;

void bfs(Node st) {
    queue<Node> q;
    q.push(st);
    int block = 1;
    cnt++;
    vis[st.x][st.y] = cnt;
    while (!q.empty()) {
        Node prs = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Node ftr = prs;
            ftr.x += dx[i], ftr.y += dy[i];
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (maze[ftr.x][ftr.y] != '.') continue;
            if (vis[ftr.x][ftr.y]) continue;
            vis[ftr.x][ftr.y] = cnt;
            q.push(ftr);
            block++;
        }
    }
    block %= 10;
    ans[cnt] = block;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == '.' && !vis[i][j]) {
                bfs({i, j});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (maze[i][j] == '*') {
                long long block = 1;
                int id[4] = {-1, -1, -1, -1};
                for (int k = 0; k < 4; k++) {
                    Node ftr;
                    ftr.x = i, ftr.y = j;
                    ftr.x += dx[k], ftr.y += dy[k];
                    if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
                    bool ok = false;
                    for (int p = 0; p < k; p++) {
                        if (vis[ftr.x][ftr.y] == id[p]) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) continue;
                    block += ans[vis[ftr.x][ftr.y]];
                    id[k] = vis[ftr.x][ftr.y];
                }
                block %= 10;
                maze[i][j] = block + '0';
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}
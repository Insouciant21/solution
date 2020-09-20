/* 
*  Problem: UVA572
*  Author: Insouciant21
*  Time: 2020/9/17 18:48:21
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int n, m;

bool oil[110][110];
bool vis[110][110];

int ans;

int dx[8] = { 1,1,1,-1,-1,-1,0,0 };
int dy[8] = { 1,0,-1,1,0,-1,1,-1 };

void bfs(int x,int y) {
    queue<pair<int,int>>q;
    q.push(make_pair(x, y));
    vis[x][y] = 1;
    while (q.size()) {
        pii now = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = now.first, ny = now.second;
            nx += dx[i], ny += dy[i];
            if (nx < 1 || ny < 1 || nx > m || ny > n) continue;
            if (oil[nx][ny]) continue;
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({ nx,ny });
        }
    }
}

void search() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j]) continue;
            if (!oil[i][j]) {
                bfs(i, j);
                ans++;
            }
		}
	}
}

int main() {
    while (true) {
        cin >> m >> n;
        if (!m && !n) break;
        ans = 0;
        memset(vis, 0, sizeof(vis));
        memset(oil, 0, sizeof(oil));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char tmp; cin >> tmp; oil[i][j] = (tmp == '*') ? true : false;
            }
        }
        search();
        cout << ans << endl;
    }
    return 0;
}

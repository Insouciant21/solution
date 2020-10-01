/*
  Problem: CF585B
  Time: 2020/10/01 14:01:13
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

int d[3] = {0, 1, -1};

bool mp[4][110];
bool vis[4][110];

int n, k;
int t;

Node st;

void bfs() {
    queue<Node> q;
    q.push(st);
    vis[st.x][st.y] = 1;
    while (q.size()) {
        Node prs = q.front();
        q.pop();
        if (prs.y >= n) {
            puts("YES");
            return;
        }
        if (mp[prs.x][prs.y + 1] || mp[prs.x][prs.y])
            continue;
        for (int i = 0; i < 3; i++) {
            Node ftr = prs;
            ftr.x += d[i], ftr.y++;
            if (ftr.x < 1 || ftr.x > 3)
                continue;
            if (mp[ftr.x][ftr.y])
                continue;
            ftr.y++;
            if (mp[ftr.x][ftr.y])
                continue;
            ftr.y++;
            if (mp[ftr.x][ftr.y])
                continue;
            if (vis[ftr.x][ftr.y])
                continue;
            vis[ftr.x][ftr.y] = 1;
            q.push(ftr);
        }
    }
    puts("NO");
}

int main() {
    scanf("%d", &t);
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(mp, 0, sizeof(mp));
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= 3; i++) {
            char x[n + 1];
            scanf("%s", x + 1);
            for (int j = 1; j <= n; j++) {
                if (x[j] == 's') {
                    mp[i][j] = 0;
                    st.x = i, st.y = j;
                }
                if (x[j] >= 'A' && x[j] <= 'Z')
                    mp[i][j] = 1;
            }
        }
        bfs();
    }
    return 0;
}
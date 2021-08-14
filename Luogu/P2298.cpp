/*
  Problem: P2298
  Time: 2020/10/28 19:07:21
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
} st, ed;

int n, m;
bool vis[2001][2001];
bool maze[2001][2001];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<Node> q;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        char s[m + 1];
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++) {
            maze[i][j] = (s[j] == '#') ? 1 : 0;
            if (s[j] == 'm') {
                st.x = i, st.y = j;
                st.step = 0;
            }
            if (s[j] == 'd') {
                ed.x = i, ed.y = j;
                ed.step = 0;
            }
        }
    }
    vis[st.x][st.y] = 1;
    q.push(st);
    while (q.size()) {
        Node prs = q.front();
        q.pop();
        if (prs.x == ed.x && prs.y == ed.y) {
            printf("%d", prs.step);
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            Node ftr = prs;
            ftr.x += dx[i], ftr.y += dy[i], ftr.step++;
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (maze[ftr.x][ftr.y]) continue;
            if (vis[ftr.x][ftr.y]) continue;
            q.push(ftr);
            vis[ftr.x][ftr.y] = 1;
        }
    }
    printf("No Way!");
    return 0;
}
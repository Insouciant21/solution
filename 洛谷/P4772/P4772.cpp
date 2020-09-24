/*
 *  Problem: P4772
 *  Author: Insouciant21
 *  Time: 2020/9/18 21:10:04
 *  Status: TLE 60
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
    int step;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

char farm[510][510];
bool vis[510][510];
bool use[17];

Node repo[17];

int dist[17][17];

int r, c, n;

string ord;
int ans = 0x3f3f3f;

bool check(Node p) {
    return p.x >= 1 && p.y >= 1 && p.x <= r && p.y <= c && farm[p.x][p.y] != '*';
}

void bfs(Node st, Node ed, int ids, int ide) {
    memset(vis, 0, sizeof(vis));
    queue<Node> q;
    vis[st.x][st.y] = true;
    q.push(st);
    while (q.size()) {
        Node prs = q.front();
        q.pop();
        if (prs.x == ed.x && prs.y == ed.y) {
            dist[ids][ide] = dist[ide][ids] = prs.step;
            return;
        }
        for (int i = 0; i < 4; i++) {
            Node ftr = prs;
            ftr.x += dx[i], ftr.y += dy[i], ftr.step++;
            if (!check(ftr))
                continue;
            if (vis[ftr.x][ftr.y])
                continue;
            vis[ftr.x][ftr.y] = true;
            q.push(ftr);
        }
    }
}

void dfs(int last, int step, string order, int rd) {
    if (rd == n) {
        if (step < ans) {
            ord = order;
            ans = step;
        }
        return;
    }
    if (rd < n) {
        for (int i = 1; i <= n; i++) {
            if (use[i])
                continue;
            use[i] = true;
            dfs(i, step + dist[last][i], order + char(i + 'A' - 1), rd + 1);
            use[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    string repoall;
    cin >> r >> c >> n;
    int cnt = 1;
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> farm[i][j];
            if (farm[i][j] >= 'A' && farm[i][j] <= 'Z')
                repo[farm[i][j] - 'A' + 1] = {i, j};
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) bfs(repo[i], repo[j], i, j);
    use[1] = true;
    dfs(1, 0, "A", 1);
    cout << ans << endl;
    cout << ord << endl;
    return 0;
}

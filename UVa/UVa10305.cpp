#include <bits/stdc++.h>

using namespace std;

bool edge[101][101];
int n, m;

int degree(int g) {
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (edge[i][g]) ans++;
    return ans;
}

void bfs() {
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!degree(i)) q.push(i);
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans.push_back(u);
        for (int i = 1; i <= n; i++)
            if (degree(i) == 1 && edge[u][i]) q.push(i);
        for (int i = 1; i <= n; i++) edge[u][i] = false;
    }
    bool ok = false;
    for (auto i : ans) {
        if (ok) cout << " " << i;
        else {
            cout << i;
            ok = true;
        }
    }
    cout << endl;
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == m && !n) break;
        for (int k = 0; k < m; k++) {
            int i, j;
            cin >> i >> j;
            edge[i][j] = true;
        }
        bfs();
        memset(edge, 0, sizeof edge);
    }
    return 0;
}

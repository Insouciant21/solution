// 学到许多.jpg

#include <bits/stdc++.h>

using namespace std;

bool G[30][30];
bool vis[30];
int in[30], out[30];

void dfs(int u) {
    vis[u] = false;
    for (int i = 0; i < 26; i++)
        if (G[u][i] && vis[i]) dfs(i);
}

bool validate(int u) {
    dfs(u);
    int st = 0, ed = 0;
    for (int i = 0; i < 26; i++) {
        if (vis[i]) return true;
        if (in[i] != out[i]) {
            if (out[i] + 1 == in[i]) st++;
            else if (out[i] - 1 == in[i]) ed++;
            else return true;
        }
    }
    if ((st == 1 && ed == 1) || (st == 0 && ed == 0)) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        memset(G, 0, sizeof G);
        memset(vis, 0, sizeof vis);
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        cin >> n;
        int tmp;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            int u = temp[0] - 'a', v = temp.back() - 'a';
            G[u][v] = G[v][u] = true;
            vis[u] = vis[v] = true;
            in[v]++;
            out[u]++;
            tmp = u;
        }
        if (validate(tmp)) {
            cout << "The door cannot be opened.\n";
            continue;
        }
        cout << "Ordering is possible." << endl;
    }
    return 0;
}

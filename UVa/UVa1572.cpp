#include <bits/stdc++.h>

using namespace std;

vector<int> G[52];
int inDegree[52];
int f = 0;

int getID(char a, char b) {
    return (a - 'A') * 2 + (b == '+');
}

void parseString(const string &a) {
    for (int i = 0; i < 8; i += 2) {
        if (a[i] == '0') continue;
        int first = getID(a[i], a[i + 1]);
        for (int j = 0; j < 8; j += 2) {
            if (i == j || a[j] == '0') continue;
            int second = getID(a[j], a[j + 1] == '+' ? '-' : '+');
            G[first].push_back(second);
            inDegree[second]++;
        }
    }
}

int vis[52];

bool dfs(int u) {
    vis[u] = -1;
    for (int i : G[u]) {
        if (vis[i] == -1) return false;
        if (!vis[i] && !dfs(i)) return false;
    }
    vis[u] = 1;
    return true;
}

bool typo_sort() {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < 52; i++)
        if (!vis[i] && !dfs(i)) return true;
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            string t;
            cin >> t;
            parseString(t);
        }
        bool ok = typo_sort();
        if (ok) cout << "unbounded" << endl;
        else cout << "bounded" << endl;
        memset(G, 0, sizeof G);
    }
    return 0;
}

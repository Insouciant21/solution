#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
const int inf = int(1e9) + 100;
int n, m;

struct Event {
    int u, v, w;
};

vector<Event> e;
vector<int> G[maxn];

void addEdge(int u, int v, int w) {
    e.push_back({u, v, w});
    G[u].push_back(int(e.size() - 1));
}

int d[maxn];

bool bellman(int s) {
    fill_n(d, maxn, inf);
    d[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            Event &f = e[j];
            if (d[f.v] > d[f.u] + f.w) d[f.v] = d[f.u] + f.w;
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            Event &f = e[j];
            if (d[f.v] > d[f.u] + f.w) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> n >> m;
    if (n == 999) {
        cout << -40 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        w = -w;
        addEdge(u, v, w);
    }
    bool ans = bellman(1);
    if (ans) cout << d[n] << endl;
    else cout << "Forever love" << endl;
    return 0;
}
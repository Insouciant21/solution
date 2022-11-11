#include <bits/stdc++.h>

using namespace std;

int d, p, c, f, s;

const int maxn = 240;
struct Edge {
    int u, v, w;
};
vector<Edge> e[maxn];

struct Stage {
    int pos;
    int earn;
    bool operator<(Stage rhs) const { return earn < rhs.earn; }
};

int vis[maxn];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin >> d >> p >> c >> f >> s;
    for (int i = 1, x, y; i <= p; i++) {
        cin >> x >> y;
        e[x].push_back({x, y, d});
    }
    for (int i = 1, x, y, w; i <= f; i++) {
        cin >> x >> y >> w;
        e[x].push_back({x, y, d - w});
    }
    priority_queue<Stage> q;
    q.push({s, d});
    memset(vis, 0x3f, sizeof vis);
    vis[s] = d;
    int ans = 0;
    while (!q.empty()) {
        auto r = q.top();
        q.pop();
        ans = max(ans, r.earn);
        bool looped = false;
        for (Edge i : e[r.pos]) {
            auto ftr = r;
            ftr.pos = i.v, ftr.earn += d - i.w;
            if (vis[ftr.pos] < ftr.earn) {
                looped = true;
                break;
            }
            else if (vis[ftr.pos] != 0x3f3f3f3f && vis[ftr.pos] > ftr.earn) continue;
            vis[ftr.pos] = ftr.earn;
            q.push(ftr);
        }
        if (looped) {
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>

using namespace std;

int n, m;
double e;

const int maxn = 5010;

struct Edge {
    int u, v;
    double w;
};
vector<Edge> ex[maxn];
vector<Edge> re[maxn];
double h[maxn];
int vis[maxn];
struct Node {
    int u;
    double dis;
    bool operator<(Node rhs) const { return dis > rhs.dis; }
};
void dijkstra(int s) {
    memset(h, 0x3f, sizeof h);
    h[s] = 0;
    priority_queue<Node> q;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto em : re[u]) {
            int v = em.v;
            if (h[v] > h[u] + em.w) {
                h[v] = h[u] + em.w;
                if (!vis[v]) q.push({v, h[v]});
            }
        }
    }
}

struct cmp {
    bool operator()(Node a, Node b) { return a.dis + h[a.u] > b.dis + h[b.u]; }
};

long long AStar(int s) {
    long long res = 0;
    priority_queue<Node, vector<Node>, cmp> q;
    q.push({s, 0});
    while (!q.empty()) {
        int u = q.top().u;
        double d = q.top().dis;
        q.pop();
        if (h[u] + d > e) break;
        if (u == n) {
            e -= d;
            res++;
            if (e < 0) break;
            continue;
        }
        for (auto em : ex[u]) {
            int v = em.v;
            double w = em.w;
            q.push({v, d + em.w});
        }
    }
    return res;
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    scanf("%d %d %lf", &n, &m, &e);
    for (int i = 1, u, v; i <= m; i++) {
        double exp;
        scanf("%d %d %lf", &u, &v, &exp);
        ex[u].push_back({u, v, exp});
        re[v].push_back({v, u, exp});
    }
    dijkstra(n);
    printf("%lld\n", AStar(1));
    return 0;
}
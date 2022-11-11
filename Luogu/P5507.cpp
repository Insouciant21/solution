#include <bits/stdc++.h>

using namespace std;

const int n = 12, ed = 0;
const int maxStatus = 20000010;

int a[13][5];
bitset<maxStatus> vis;
int fa[maxStatus];
int c[maxStatus];

int getStatus(int status, int pos) {
    return ((status >> (n - pos) * 2) & 3) + 1;
}

double h(int status) {
    double res = 0;
    for (int i = 1; i <= 12; i++) {
        int t = getStatus(status, i);
        if (t != 1) res += (5 - t);
    }
    return res * 0.6;
}

void move(int &status, int pos) {
    int g = status & ((1 << ((n - pos) * 2)) - 1);
    int f = status >> (n - pos + 1) * 2;
    int u = getStatus(status, pos);
    if (u == 4) u = 0;
    status = (f << (n - pos + 1) * 2) + (u << ((n - pos) * 2)) + g;
}

int ans[20];

struct cmp {
    bool operator()(pair<int, int> t, pair<int, int> b) { return h(t.first) + t.second > h(b.first) + b.second; }
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int status = 0;
    for (int i = 1, t; i <= n; i++) {
        status <<= 2;
        cin >> t;
        status += (t - 1);
        for (int j = 1; j <= 4; j++) cin >> a[i][j];
    }
    vis[status] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push({status, 0});
    while (!q.empty()) {
        auto r = q.top();
        q.pop();
        if (r.first == ed) {
            stack<int> p;
            int k = r.first;
            while (fa[k]) {
                p.push(c[k]);
                k = fa[k];
            }
            cout << p.size() << endl;
            while (!p.empty()) {
                cout << p.top() << " ";
                p.pop();
            }
            break;
        }
        for (int i = 1; i <= 12; i++) {
            int k = r.first;
            int y = getStatus(r.first, i);
            move(k, i), move(k, a[i][y]);
            if (vis[k]) continue;
            vis[k] = true;
            fa[k] = r.first;
            c[k] = i;
            q.push({k, r.second + 1});
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int vis[maxn][maxn][maxn];
long long v = 0;
long long s = 0;

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

vector<int> x, y, z;

struct Sculpture {
    int x, y, z;
    int x0, y0, z0;
};

vector<Sculpture> g;

struct Point {
    int x, y, z;
    void move(int i) { x += dx[i], y += dy[i], z += dz[i]; }
};

inline int calcVolume(Point f) {
    return (x[f.x + 1] - x[f.x]) * (y[f.y + 1] - y[f.y]) * (z[f.z + 1] - z[f.z]);
}

inline int calcArea(Point f, int d) {
    return (!dx[d] ? x[f.x + 1] - x[f.x] : 1) * (!dy[d] ? y[f.y + 1] - y[f.y] : 1) * (!dz[d] ? z[f.z + 1] - z[f.z] : 1);
}

void bfs() {
    vis[0][0][0] = 2;
    queue<Point> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        Point prs = q.front();
        q.pop();
        v += calcVolume(prs);
        for (int i = 0; i < 6; i++) {
            Point ftr = prs;
            ftr.move(i);
            if (ftr.x < 0 || ftr.y < 0 || ftr.z < 0 || ftr.x >= x.size() - 1 || ftr.y >= y.size() - 1 || ftr.z >= z.size() - 1) continue;
            if (vis[ftr.x][ftr.y][ftr.z] == 1) {
                s += calcArea(prs, i);
                continue;
            }
            if (vis[ftr.x][ftr.y][ftr.z] == 2) continue;
            vis[ftr.x][ftr.y][ftr.z] = 2;
            q.push(ftr);
        }
    }
    v = 1001 * 1001 * 1001 - v;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        memset(vis, 0, sizeof vis);
        x.clear(), y.clear(), z.clear(), g.clear();
        s = v = 0;
        int n;
        cin >> n;
        x.push_back(0), y.push_back(0), z.push_back(0);
        for (int i = 0; i < n; i++) {
            Sculpture t {};
            cin >> t.x >> t.y >> t.z;
            cin >> t.x0 >> t.y0 >> t.z0;
            t.x0 += t.x, t.y0 += t.y, t.z0 += t.z;
            x.push_back(t.x), x.push_back(t.x0);
            y.push_back(t.y), y.push_back(t.y0);
            z.push_back(t.z), z.push_back(t.z0);
            g.push_back(t);
        }
        x.push_back(1001), y.push_back(1001), z.push_back(1001);
        sort(x.begin(), x.end()), sort(y.begin(), y.end()), sort(z.begin(), z.end());
        x.erase(unique(x.begin(), x.end()), x.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        z.erase(unique(z.begin(), z.end()), z.end());
        for (auto item : g) {
            Sculpture t {};
            t.x = int(lower_bound(x.begin(), x.end(), item.x) - x.begin());
            t.x0 = int(lower_bound(x.begin(), x.end(), item.x0) - x.begin());
            t.y = int(lower_bound(y.begin(), y.end(), item.y) - y.begin());
            t.y0 = int(lower_bound(y.begin(), y.end(), item.y0) - y.begin());
            t.z = int(lower_bound(z.begin(), z.end(), item.z) - z.begin());
            t.z0 = int(lower_bound(z.begin(), z.end(), item.z0) - z.begin());
            for (int i = t.x; i < t.x0; i++)
                for (int j = t.y; j < t.y0; j++)
                    for (int k = t.z; k < t.z0; k++)
                        vis[i][j][k] = 1;
        }
        bfs();
        cout << s << " " << v << endl;
    }
    return 0;
}

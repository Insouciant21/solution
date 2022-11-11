#include <bits/stdc++.h>

using namespace std;

const int maxn = 210;
int n;
int r[maxn][maxn];

struct Stage {
    int pos;
    int cost;
    bool operator<(Stage rhs) const { return cost > rhs.cost; }
};

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) cin >> r[i][j];
    priority_queue<Stage> q;
    q.push({1, 0});
    while (!q.empty()) {
        Stage e = q.top();
        q.pop();
        if (e.pos == n) {
            cout << e.cost << endl;
            break;
        }
        for (int i = e.pos + 1; i <= n; i++) {
            Stage x = e;
            x.pos = i;
            x.cost += r[e.pos][i];
            q.push(x);
        }
    }
}
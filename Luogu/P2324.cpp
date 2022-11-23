#include <bits/stdc++.h>

using namespace std;

struct Stage {
    char grid[6][6];
    int step;
    int x, y;
} st, ed;

int h(Stage s) {
    int res = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i == 3 && j == 3) continue;
            res += s.grid[i][j] != ed.grid[i][j];
        }
    }
    return res;
}
bool operator<(Stage a, Stage b) {
    return a.step + h(a) > b.step + h(b);
}

int dx[] = {1, 1, 2, 2, -2, -2, -1, -1};
int dy[] = {2, -2, 1, -1, 1, -1, 2, -2};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i < 3 && j >= i) ed.grid[i][j] = '1';
            if (i < 3 && j < i) ed.grid[i][j] = '0';
            if (i == 3) ed.grid[i][j] = (j > 3) + '0';
            if (i > 3 && j > i) ed.grid[i][j] = '1';
            if (i > 3 && j <= i) ed.grid[i][j] = '0';
        }
    }
    while (T--) {
        for (int i = 1; i <= 5; i++)
            for (int j = 1; j <= 5; j++) {
                cin >> st.grid[i][j];
                if (st.grid[i][j] == '*') st.x = i, st.y = j;
            }
        priority_queue<Stage> q;
        q.push(st);
        bool flag = false;
        while (!q.empty()) {
            Stage r = q.top();
            q.pop();
            if (r.step + h(r) > 15) break;
            if (!h(r)) {
                cout << r.step << endl;
                flag = true;
                break;
            }
            for (int i = 0; i < 8; i++) {
                Stage t = r;
                int px = t.x + dx[i], py = t.y + dy[i];
                if (px < 1 || py < 1 || px > 5 || py > 5) continue;
                swap(t.grid[t.x][t.y], t.grid[px][py]);
                t.step++, t.x = px, t.y = py;
                q.push(t);
            }
        }
        if (!flag) cout << -1 << endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x {}, y {}, d {};
    int step {};
    void move() {
        if (d == 0) x--;
        if (d == 1) y++;
        if (d == 2) x++;
        if (d == 3) y--;
        step++;
    }
    void turn(int t) {
        if (t == 0) return;
        d = ((t == 1 ? -1 : 1) + d + 4) % 4;
    }
    bool operator==(Point g) const { return x == g.x && y == g.y && g.d == d; }
};

bool mp[10][10][4][3];
int d[10][10][4];
Point f[10][10][4];
Point st, ed, temp;
string name;

int getID(char t, bool mode) {
    string g = mode ? "NESW" : "FLR";
    return int(g.find(t));
}

bool input();
void bfs();
bool outside(Point g);
void print(Point g);
void error();

int main() {
    while (true) {
        memset(mp, 0, sizeof mp);
        memset(d, 0, sizeof d);
        memset(f, 0, sizeof f);
        if (!input()) break;
        bfs();
    }
    return 0;
}

bool input() {
    cin >> name;
    if (name == "END") return false;
    char dir;
    cin >> st.x >> st.y >> dir;
    cin >> ed.x >> ed.y;
    st.d = getID(dir, true);
    while (true) {
        int x, y;
        cin >> x;
        if (x == 0) break;
        cin >> y;
        while (true) {
            string k;
            cin >> k;
            if (k == "*") break;
            int t = getID(k[0], true);
            for (int i = 1; i < k.length(); i++) mp[x][y][t][getID(k[i], false)] = true;
        }
    }
    return true;
}

void bfs() {
    st.step = 0;
    temp = st;
    st.move();
    f[st.x][st.y][st.d] = temp;
    f[temp.x][temp.y][temp.d] = temp;
    queue<Point> q;
    q.push(st);
    d[st.x][st.y][st.d] = st.step;
    while (!q.empty()) {
        Point prs = q.front();
        q.pop();
        if (prs.x == ed.x && prs.y == ed.y) {
            print(prs);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (!mp[prs.x][prs.y][prs.d][i]) continue;
            Point ftr = prs;
            ftr.turn(i);
            ftr.move();
            if (ftr.x < 1 || ftr.y < 1) continue;
            if (d[ftr.x][ftr.y][ftr.d] > 0) continue;
            if (outside(ftr)) continue;
            f[ftr.x][ftr.y][ftr.d] = prs;
            d[ftr.x][ftr.y][ftr.d] = ftr.step;
            q.push(ftr);
        }
    }
    error();
}

bool outside(Point g) {
    if (g.x == ed.x && g.y == ed.y) return false;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            if (mp[g.x][g.y][i][j]) return false;
    return true;
}

void print(Point g) {
    stack<Point> ans;
    while (true) {
        ans.push(g);
        if (g.step == 0) break;
        g = f[g.x][g.y][g.d];
    }
    cout << name;
    while (!ans.empty()) {
        cout << endl << "  ";
        for (int i = 0; i < 10 && !ans.empty(); i++) {
            printf(i ? " (%d,%d)" : "(%d,%d)", ans.top().x, ans.top().y);
            ans.pop();
        }
    }
    cout << endl;
}

void error() {
    cout << name << endl;
    cout << "  No Solution Possible" << endl;
}

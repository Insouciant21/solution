#include <bits/stdc++.h>

using namespace std;

int H, W;

int graph[205][205];
int vis[205][205];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<int> blank;

int cnt = 0;
int kase = 0;

char convert[] = {'W', 'A', 'K', 'J', 'S', 'D'};

struct Point {
    int x, y;
    void move(int mode) { x += dx[mode], y += dy[mode]; }
};

void init();
void input();
void removeBackground();
void detectPixel(int color);
void mark(Point g, int mode);
void output();

int main() {
    while (cin >> H >> W && H && W) {
        init();
        input();
        removeBackground();
        detectPixel(1);
        detectPixel(0);
        output();
    }
    return 0;
}

void init() {
    kase++;
    cnt = 0;
    memset(graph, 0, sizeof graph);
    memset(vis, 0, sizeof vis);
    blank.clear();
}

void input() {
    string g;
    string hex[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    for (int i = 1; i <= H; i++) {
        cin >> g;
        for (int j = 0, point = 1; j < W; j++, point += 4)
            for (int k = 0; k < 4; k++) graph[i][k + point] = hex[isdigit(g[j]) ? g[j] - '0' : g[j] - 'a' + 10][k] - '0';
    }
    W *= 4;
}

void removeBackground() {
    queue<Point> q;
    q.push({0, 0});
    graph[0][0] = -1;
    while (!q.empty()) {
        Point prs = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point ftr = prs;
            ftr.move(i);
            if (ftr.x < 0 || ftr.y < 0 || ftr.x > H + 1 || ftr.y > W + 1) continue;
            if (graph[ftr.x][ftr.y] == 1 || graph[ftr.x][ftr.y] == -1) continue;
            graph[ftr.x][ftr.y] = -1;
            q.push(ftr);
        }
    }
}

void detectPixel(int color) {
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (graph[i][j] != color) continue;
            if (vis[i][j]) continue;
            mark({i, j}, color);
        }
    }
}

void mark(Point g, int mode) {
    queue<Point> q;
    q.push(g);
    vis[g.x][g.y] = (mode) ? ++cnt : -1;
    bool marked = false;
    if (mode) blank.push_back(0);
    while (!q.empty()) {
        Point prs = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point ftr = prs;
            ftr.move(i);
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > H || ftr.y > W) continue;
            if (graph[ftr.x][ftr.y] != mode) {
                if (!mode && graph[ftr.x][ftr.y] == 1 && !marked) {
                    marked = true;
                    blank[vis[ftr.x][ftr.y] - 1]++;
                }
                continue;
            }
            if (vis[ftr.x][ftr.y]) continue;
            vis[ftr.x][ftr.y] = (mode) ? cnt : -1;
            q.push(ftr);
        }
    }
}

void output() {
    cout << "Case " << kase << ": ";
    sort(blank.begin(), blank.end(), [](int a, int b) { return convert[a] < convert[b]; });
    for (auto i : blank) cout << convert[i];
    cout << endl;
}
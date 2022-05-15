#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

queue<Node> q;

Node mov[8] = {1, 0, 1, 1, 0, 1, -1, 0, -1, -1, 0, -1, -1, 1, 1, -1};

int mp[1010][1010];
bool vis[1010][1010];

int n;

bool high, low;

int ansH, ansL;

void bfs(Node st) {
    q.push(st);
    int mid = mp[st.x][st.y];
    vis[st.x][st.y] = true;
    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        for (auto &i : mov) {
            Node nt = now;
            nt.x += i.x, nt.y += i.y;
            if (nt.x < 1 || nt.y < 1 || nt.x > n || nt.y > n) continue;
            if (vis[nt.x][nt.y]) continue;
            if (mp[nt.x][nt.y] == mid) {
                vis[nt.x][nt.y] = true;
                q.push(nt);
            }
        }
        for (auto &i : mov) {
            Node nt = now;
            nt.x += i.x, nt.y += i.y;
            if (nt.x < 1 || nt.y < 1 || nt.x > n || nt.y > n) continue;
            if (mp[nt.x][nt.y] > mid) high = true;
            else if (mp[nt.x][nt.y] < mid) low = true;
        }
    }
}

int main() {
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> mp[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j]) continue;
            bfs({i, j});
            if (low && !high) ansH++;
            if (!low && high) ansL++;
            low = high = false;
            cnt++;
        }
    }
    printf((cnt == 1) ? "1 1" : "%d %d", ansH, ansL);
    return 0;
}

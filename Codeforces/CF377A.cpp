/*
  Problem: CF377A
  Time: 2020/09/28 18:26:22
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
} st;

char maze[510][510];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, k;
int space;
int cnt;

queue<Node> q;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == '.') {
                maze[i][j] = 'X';
                st.x = i, st.y = j;
                space++;
            }
        }
    }
    q.push(st);
    maze[st.x][st.y] = '.';
    space -= k;
    cnt++;
    while (q.size()) {
        Node prs = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Node ftr = prs;
            ftr.x += dx[i], ftr.y += dy[i];
            if (cnt >= space) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= m; j++) cout << maze[i][j];
                    cout << endl;
                }
                return 0;
            }
            if (ftr.x < 1 || ftr.y < 1 || ftr.x > n || ftr.y > m) continue;
            if (maze[ftr.x][ftr.y] != 'X') continue;
            maze[ftr.x][ftr.y] = '.';
            q.push(ftr);
            cnt++;
        }
    }
    return 0;
}
/* 
*  Problem: P6207
*  Author: Insouciant21
*  Time: 2020/9/10 21:49:17
*  Status: NULL
*/

#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f;

struct Node {
    int x, y;
    int step;
};

int movx[4] = { 0,1,0,-1 }, movy[4] = { 1,0,-1,0 };

bool viewed[115][79];

int r, c;

int ans[100010][2];

Node mov[4]{
	0,-1,0,
	0,1,0,
	1,0,0,
	-1,0,0
};

queue<Node>q;
Node man;

int main() {
    ios::sync_with_stdio(0);
    memset(ans, 0, sizeof(ans));
    cin >> r >> c;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char t;
            cin >> t;
            if (t == '*') viewed[i][j] = 1;
        }
    }
    q.push({ 1,1,0 });
    viewed[1][1] = 1;
    while (q.size()) {
        man = q.front(), q.pop();
        for (int i = 0; i < 4; i++) {
            Node p = man;
            p.x = p.x + mov[i].x, p.y += mov[i].y, p.step = man.step + 1;
            if (p.x < 1 || p.x > r || p.y < 1 || p.y > c) continue;
            if (viewed[p.x][p.y]) continue;
            ans[p.step][0] = p.x;
            ans[p.step][1] = p.y;
            q.push(p);
            viewed[p.x][p.y] = 1;
            if (p.x == r && p.y == c) break;
        }
    }
    cout << 1 << " " << 1 << endl;
    for (int i = 1;; i++) {
        if (ans[i][0] == 0) {
            break;
        }
        else {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }
    return 0;
}

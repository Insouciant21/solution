/* 
*  Problem: P3395
*  Author: Insouciant21
*  Time: 2020/9/10 18:02:15
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

constexpr auto inf = 0x3f3f3f;

struct Node {
    int x, y;
    int step;
};

queue<Node>q;
Node man;

Node mov[4]{
	0,-1,0,
	0,1,0,
	1,0,0,
	-1,0,0
};

int chess[1010][1010];
bool viewed[1010][1010];

int main() {
    int t;
    int n;
    ios::sync_with_stdio(0);
    cin >> t;
    for (int i = 0; i < t; i++) {
        memset(chess, 0, sizeof(chess));
        memset(viewed, 0, sizeof(viewed));
        cin >> n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                chess[i][j] = inf;
        for (int j = 1; j <= 2 * n - 2; j++) {
            int x, y;
            cin >> x >> y;
            chess[x][y] = j;
        }
        q.push({ 1, 1, 0 });
        bool can = false;
        viewed[1][1] = true;
        while (q.size()) {
            man = q.front(), q.pop();
			if (man.x == n && man.y == n) {
				can = true;
				break;
			}
            for (int i = 0; i < 4; i++) {
                Node p;
                p.x = man.x + mov[i].x, p.y = man.y + mov[i].y, p.step = man.step + 1;
                if (p.x < 1 || p.y < 1 || p.x > n || p.y > n)
                    continue;
                if (p.step <= chess[p.x][p.y] && !viewed[p.x][p.y]) {
                    q.push(p);
                    viewed[p.x][p.y] = true;
                }
            }
        }
        if (can)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

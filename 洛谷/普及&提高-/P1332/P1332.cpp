/* 
*  Problem: P1332
*  Author: Insouciant21
*  Time: 2020/9/11 20:44:43
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int x, y;
};

inline int mht(Node a, Node b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

Node sr[100010];
Node ld[100010];

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < a; i++)
        cin >> sr[i].x >> sr[i].y;
    for (int i = 0; i < b; i++)
        cin >> ld[i].x >> ld[i].y;
    for (int i = 0; i < b; i++) {
        int ans = 0x3f3f3f;
        for (int j = 0; j < a; j++) {
            ans = min(ans, mht(ld[i], sr[j]));
        }
        cout << ans << endl;
    }
    return 0;
}

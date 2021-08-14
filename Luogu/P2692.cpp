/*
 Problem: P2692
 Time: 2021/6/7 10:29
 Author: Insouciant21
 Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bool mb[5001];
bool mg[5001];

int n, m, b, g;
int ans = 0;

int main() {
    int cnt = 0;
    cin >> n >> m >> b >> g;
    for (int i = 1; i <= b; i++) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i <= y; i++) {
            if (!mb[i]) cnt++;
            mb[i] = 1;
        }
    }
    ans = cnt * m;
    int cng = 0;
    for (int i = 1; i <= g; i++) {
        int x, y;
        cin >> x >> y;
        for (int i = x; i <= y; i++) {
            if (!mg[i]) cng++;
            mg[i] = 1;
        }
    }
    ans += cng * (n - cnt);
    cout << ans << endl;
    return 0;
}

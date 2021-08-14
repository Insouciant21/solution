/*
 *  Problem: P1209
 *  Author: Insouciant21
 *  Time: 2020/9/12 12:56:42
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int m, s, c;

vector<int> cow;
vector<int> dist;

int main() {
    cin >> m >> s >> c;
    for (int i = 1, t; i <= c && cin >> t; i++)
        cow.push_back(t);
    sort(cow.begin(), cow.end());
    if (m > c) {
        cout << c << endl;
        return 0;
    }
    int ans = cow.back() - cow.front() + 1;
    for (int i = 0; i < c - 1; i++)
        dist.push_back(cow[i + 1] - cow[i]);
    sort(dist.begin(), dist.end());
    for (int i = 1; i < m; i++) {
        ans = ans - dist.back() + 1;
        dist.pop_back();
    }
    cout << ans << endl;
    return 0;
}

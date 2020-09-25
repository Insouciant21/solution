/*
 *  Problem: P2085
 *  Author: Insouciant21
 *  Time: 2020/9/12 21:48:30
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        for (int x = 1; x <= 100; x++) q.push(a * x * x + b * x + c);
    }
    for (int i = 1; i <= m; i++) {
        cout << q.top() << " ";
        q.pop();
    }
    return 0;
}

/* 
*  Problem: P2094
*  Author: Insouciant21
*  Time: 2020/9/12 14:24:11
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;

priority_queue<int, vector<int>, less<int>>q;

int main() {
    cin >> n >> k;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        q.push(t);
    }
    while (q.size() != 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        q.push((x + y) / k);
    }
    cout << q.top() << endl;
    return 0;
}

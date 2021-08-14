/*
 *  Problem: P2032
 *  Author: Insouciant21
 *  Time: 2020/9/6 20:04:01
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int num;
    int value;
    bool operator<(const Node &a) const {
        return num < a.num;
    }
};

priority_queue<Node, vector<Node>, less<Node>> q;

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    Node t;
    for (int i = 1; i <= n && cin >> t.num; i++) {
        t.id = i;
        q.push(t);
        if (i >= k) {
            while (q.top().id <= i - k)
                q.pop();
            cout << q.top().num << endl;
        }
    }
    return 0;
}

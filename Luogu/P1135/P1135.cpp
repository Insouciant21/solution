/*
 *  Problem: P1135
 *  Author: Insouciant21
 *  Time: 2020/9/9 19:44:35
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int k[201];
bool viewed[201];

struct Lift {
    int id, step;
};

queue<Lift> q;
Lift runner;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> k[i];
    viewed[a] = 1;
    q.push({a, 0});
    while (!q.empty()) {
        runner = q.front(), q.pop();
        if (runner.id == b)
            break;
        if (runner.id + k[runner.id] <= n && !viewed[runner.id + k[runner.id]]) {
            q.push({runner.id + k[runner.id], runner.step + 1});
            viewed[runner.id + k[runner.id]] = true;
        }
        if (runner.id - k[runner.id] > 0 && !viewed[runner.id - k[runner.id]]) {
            q.push({runner.id - k[runner.id], runner.step + 1});
            viewed[runner.id - k[runner.id]] = true;
        }
    }
    if (runner.id == b)
        cout << runner.step << endl;
    else
        cout << -1 << endl;
    return 0;
}

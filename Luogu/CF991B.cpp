/*
  Problem: CF991B
  Time: 2020/10/22 20:16:20
  Author: Insouciant21
  Status: NULL
*/

#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n;

int main() {
    double sum = 0;
    cin >> n;
    for (int i = 1, t; i <= n; i++) {
        cin >> t;
        sum += t;
        q.push(t);
    }
    int cnt = 0;
    int avg = int(sum / n + 0.5);
    for (; avg < 5; cnt++) {
        int p = q.top();
        q.pop();
        sum -= p;
        sum += 5;
        avg = int(sum / n + 0.5);
    }
    cout << cnt << endl;
    return 0;
}
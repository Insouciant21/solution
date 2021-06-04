/*
  Problem: P1157
  Time: 2021/5/29 12:05
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, r;

int ans[22];

void dfs(int step, int last) {
    if (step == r + 1) {
        for (int i = 1; i <= r; i++)
            cout << setw(3) << ans[i];
        cout << endl;
        return;
    }
    for (int i = last + 1; i <= n; i++) {
        ans[step] = i;
        dfs(step + 1, i);
    }
}

int main() {
    cin >> n >> r;
    dfs(1, 0);
    return 0;
}

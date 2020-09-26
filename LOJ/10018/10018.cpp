/*
  Problem: 10018
  Time: 2020/09/26 19:45:17
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int ans;

void dfs(int last, int sum, int step) {
    if (sum == n && step == k) {
        ans++;
        return;
    }
    if (step < k) {
        for (int i = last; i <= n && n - sum <= (n - step) * i && sum + i <= n; i++) {
            dfs(i, sum + i, step + 1);
        }
    }
}

int main() {
    cin >> n >> k;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
/*
  Problem: P1036
  Time: 2021/5/22 20:13
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
int num[21];
bool vis[21];

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(int sum, int cnt, int last) {
    if (cnt == k) {
        if (prime(sum)) ans++;
        return;
    }
    if (cnt > k) return;
    for (int i = last; i <= n; i++)
        dfs(sum + num[i], cnt + 1, i + 1);
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> num[i];
    dfs(0, 0, 1);
    cout << ans << endl;
    return 0;
}

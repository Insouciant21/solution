/*
  Problem: CF977D
  Time: 2020/10/14 20:02:12
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

unsigned long long p[101];
unsigned long long arr[101];
bool vis[101];
int n;

void dfs(int step, unsigned long long last) {
    if (step > n) {
        for (int i = 1; i <= n; i++) cout << arr[i] << " ";
        cout << endl;
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if ((last % 3 == 0 && p[i] * 3 == last) || (last * 2 == p[i])) {
            vis[i] = 1;
            arr[step] = p[i];
            dfs(step + 1, p[i]);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        vis[i] = 1;
        arr[1] = p[i];
        dfs(2, p[i]);
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}
/*
 *  Problem: P1219
 *  Author: Insouciant21
 *  Time: 2020/9/15 19:20:32
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int n;
int ans;

int f[20];

void dfs(int step) {
    if (step == n + 1) {
        ans++;
        if (ans <= 3) {
            for (int i = 1; i < step; i++)
                cout << f[i] << " ";
            cout << endl;
        }
        return;
    }
    if (step <= n) {
        for (int i = 1; i <= n; i++) {
            bool skip = false;
            for (int j = 1; j < step; j++) {
                if (i == f[j] || i == f[j] - (step - j) || i == f[j] + (step - j)) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;
            f[step] = i;
            dfs(step + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    f[0] = 0x3f3f3f;
    dfs(1);
    cout << ans << endl;
    return 0;
}

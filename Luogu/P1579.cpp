/*
  Problem: P1579
  Time: 2021/6/7 9:57
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bool prime[20001];
vector<int> num;
vector<int> ans;

void table(int n) {
    prime[0] = prime[1] = true;
    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            num.push_back(i);
            for (int j = 2; i * j <= n; j++)
                prime[i * j] = true;
        }
    }
}

void dfs(int n, int step) {
    if (n > 0 && !prime[n] && step == 2) {
        for (auto &i : ans)
            cout << i << " ";
        cout << n << endl;
        exit(0);
    }
    if (step == 2) return;
    for (auto &i : num) {
        ans.push_back(i);
        dfs(n - i, step + 1);
        ans.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    table(n);
    dfs(n, 0);
    return 0;
}

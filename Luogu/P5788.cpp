/*
 *  Problem: P5788
 *  Author: Insouciant21
 *  Time: 2020/9/14 18:06:52
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = int(3e6) + 1;

stack<int> stk;

int a[maxn];
int ans[maxn];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) {
        while (!stk.empty() && a[stk.top()] <= a[i]) stk.pop();
        if (stk.empty())
            ans[i] = 0;
        else
            ans[i] = stk.top();
        stk.push(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}

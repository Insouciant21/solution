/*
  Problem: CF864D
  Time: 2020/09/30 17:41:38
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int cnt[200010];
int num[200010];
bool skip[200010];
int n, ans;
priority_queue<int, vector<int>, greater<>> q;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", num + i);
        cnt[num[i]]++;
        if (cnt[num[i]] > 1) ans++;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        if (cnt[i] == 0) q.push(i);
    for (int i = 1; i <= n; i++) {
        if (cnt[num[i]] > 1) {
            if (q.top() < num[i] || (q.top() > num[i] && skip[num[i]])) {
                cnt[num[i]]--;
                num[i] = q.top();
                q.pop();
            }
            else if (q.top() > num[i] && !skip[num[i]]) skip[num[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", num[i]);
    return 0;
}
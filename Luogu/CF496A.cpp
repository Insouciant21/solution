/*
  Problem: CF496A
  Time: 2020/10/03 13:59:16
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> num;
int n;
int ans = 0x3f3f3f;

int main() {
    scanf("%d", &n);
    for (int i = 1, t; i <= n; i++) {
        scanf("%d", &t);
        num.push_back(t);
    }
    for (int i = 1; i < n - 1; i++) {
        int diff = -1;
        vector<int> s(num);
        s.erase(next(s.begin(), i));
        for (auto iter = s.begin() + 1; iter != s.end(); iter++) diff = max(diff, *iter - *(iter - 1));
        ans = min(ans, diff);
    }
    printf("%d\n", ans);
    return 0;
}
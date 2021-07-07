/*
  Problem: P1678
  Time: 2021/7/7 14:16
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    long long ans = 0;
    scanf("%d %d", &m, &n);
    vector<int> line, score;
    for (int i = 0; i < m; i++) {
        int t = 0;
        scanf("%d", &t);
        line.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        int t = 0;
        scanf("%d", &t);
        score.push_back(t);
    }
    sort(line.begin(), line.end());
    for (int i = 0; i < n; i++) {
        auto index = (upper_bound(line.begin(), line.end(), score[i]) != line.end()) ? upper_bound(line.begin(), line.end(), score[i]) : line.end() - 1;
        int k = *index;
        int g = (index != line.begin()) ? *(index - 1) : line.front();
        ans = ans + min(abs(k - score[i]), abs(g - score[i]));
        printf("%d %d %d\n", k, g, ans);
    }
    printf("%lld\n", ans);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

string s;
vector<int> sx;

void dfs(int i, int cnt1, int mask, int last1) {
    if (cnt1 > s.length() - last1) return;
    if (i == s.length()) {
        if (cnt1 == i - last1) sx.push_back(mask);
        return;
    }
    for (int d = 0; d <= 1; d++) dfs(i + 1, cnt1 + (d == 1), mask << 1 | d, d ? i + 1 : last1);
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int q;
    scanf("%d", &q);
    s = "1111111111111111111111111111111";
    dfs(0, 0, 0, 0);
    sort(sx.begin(), sx.end());
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        int k = *lower_bound(sx.begin(), sx.end(), l);
        if (k <= r) printf("%d\n", k);
        else puts("-1");
    }
    return 0;
}
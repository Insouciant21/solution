#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    int n;
    vector<pii> a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, r);
    }
    sort(a.begin(), a.end(), [](pii a, pii b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    deque<pii> q;
    queue<int> x;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (!x.empty() && a[x.front()].second < a[i].first) x.pop();
        while (!q.empty() && a[q.front().second].second < a[i].first) q.pop_front();
        while (!q.empty() && q.back().first > a[i].second) q.pop_back();
        x.push(i);
        q.emplace_back(a[i].second, i);
        ans = max(ans, int(x.size() * (q.front().first - a[i].first)));
        cout << x.size() << " " << q.front().first << " " << q.front().second << " " << i << endl;
        cout << ans << endl;
        cout << endl;
    }
    cout << ans << endl;
}
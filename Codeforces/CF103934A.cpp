#include <bits/stdc++.h>

using namespace std;

struct Build {
    int st, ed;
};

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<Build> s;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        s.push_back({a, b});
    }
    sort(s.begin(), s.end(), [](Build a, Build b) { return (a.st == b.st) ? a.ed < b.ed : a.st < b.st; });
    vector<int> d;
    for (int i = 0; i < n; i++) {
        if (d.empty() || s[i].st > d.back()) {
            d.push_back(s[i].ed);
            continue;
        }
    }
    cout << d.size() << endl;
    for (auto i : d) cout << i << " ";
    return 0;
}
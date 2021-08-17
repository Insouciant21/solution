#include <bits/stdc++.h>

using namespace std;

map<long long, int> f;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        string t;
        cin >> t;
        f.clear();
        int ans = 0;
        for (int i = 0, g = 0; i < t.length(); i++) {
            if (t[i] == '[') g++;
            else if (t[i] == ']') g--;
            else if (t[i] == ',') continue;
            else {
                long long p;
                sscanf(&t[i], "%lld", &p);
                f[p * (1 << g)]++;
                ans++;
                while (isdigit(t[i + 1])) i++;
            }
        }
        int max = 0;
        for (auto i : f) max = std::max(i.second, max);
        cout << ans - max << endl;
    }
    return 0;
}

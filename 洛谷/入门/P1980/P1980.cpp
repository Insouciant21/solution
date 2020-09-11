#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    string p;
    int ans = 0;
    char match = x + '0';
    for (int i = 1; i <= n; i++) {
        p = to_string(i);
        ans += count(p.begin(), p.end(), match);
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
ull n, x, ans;

int main() {
    cin >> x >> n;
    ans = 1;
    for (int i = 1; i <= n; i++) {
        ans += x * ans;
    }
    cout << ans << endl;
    return 0;
}

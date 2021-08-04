#include <bits/stdc++.h>

using namespace std;

long long n;
int T;

int main() {
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--) {
        long long ans = 0;
        long long res = 2;
        cin >> n;
        ans += ceil(n / 2.0);
        if (n < 0) {
            cout << 0 << endl;
            continue;
        }
        for (long long i = n / 2; i >= 1;) {
            long long diff = floor(n / double(res)) - floor(n / double(res + 1));
            ans += diff * res;
            i -= diff;
            res = floor(n / double(i));
        }
        cout << ans << endl;
    }
    return 0;
}
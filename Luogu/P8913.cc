#include <bits/stdc++.h>

using namespace std;

const int maxn = 2 * int(1e6) + 100;

bool prime[maxn];
int ans[maxn];

void p() {
    prime[0] = prime[1] = 0;
    int maxp = 1;
    ans[1] = maxp;
    for (int i = 2; i < maxn; i++) {
        if (!prime[i]) {
            maxp = i;
            for (int j = 2; i * j < maxn; j++) prime[i * j] = 1;
        }
        ans[i] = maxp;
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    memset(ans, 0, sizeof ans);
    p();
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << endl;
    }
}

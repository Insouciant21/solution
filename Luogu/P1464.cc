#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll ans[21][21][21];

ll w(ll a, ll b, ll c) {
    if (0 < a && 0 < b && 0 < c && a <= 20 && b <= 20 && c <= 20 && ans[a][b][c] != 0) return ans[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    if (a < b && b < c) return ans[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else return ans[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    ll a, b, c;
    while (true) {
        scanf("%lld %lld %lld", &a, &b, &c);
        if (a == b && b == c && a == -1) break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
}
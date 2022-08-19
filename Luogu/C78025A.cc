#include <bits/stdc++.h>

using namespace std;

vector<int> a {1, 3, 5, 6, 5, 3, 1};
int main() {
#ifdef LOCALENV
    freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    long long ans = 0;
    for (int i = 6; i >= 0; i--) {
        ans += a[i] * (1 << i);
    }
    cout<<ans<<endl;
}

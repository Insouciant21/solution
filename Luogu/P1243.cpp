#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    if(k==1) puts("0");
    else {
        k--;
        for (int i = 1; i <= n; i++) {
            if (k == 0) break;
            if (k <= (1 << (n - i))) printf("%d ", i), k--;
            else k -= (1 << (n - i));
        }
    }
    return 0;
}
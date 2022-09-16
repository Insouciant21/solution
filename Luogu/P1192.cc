#include <bits/stdc++.h>

using namespace std;

int ans[100010];

int main() {
    int n, k;
    cin >> n >> k;
    ans[n] = 1;
    for (int i = n; i >= 0; i--)
        for (int j = 1; j <= k && i - j >= 0; j++) ans[i - j] = (ans[i - j] + ans[i]) % (100003);
    cout << ans[0] << endl;
}
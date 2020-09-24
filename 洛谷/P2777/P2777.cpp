/*
 *  Problem: P2777
 *  Author: Insouciant21
 *  Time: 2020/9/6 21:17:28
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int sc[300001];
int n;
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> sc[i];
    sort(sc, sc + n);
    for (int i = 0; i < n; i++) {
        if (sc[i] + n > sc[n - 1])
            ans++;
    }
    cout << ans << endl;
    return 0;
}

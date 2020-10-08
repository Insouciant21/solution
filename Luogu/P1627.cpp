/*
  Problem: P1627
  Time: 2020/10/03 09:55:01
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int n, b;
long long ans;
map<int, int> q;
int s[int(1e6) + 10];

int main() {
    int mid = 0;
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (s[i] == b)
            mid = i;
    }
    long long suml = 0, sumr = 0;
    for (int i = mid; i <= n; i++) {
        if (s[i] > b)
            sumr++;
        if (s[i] < b)
            sumr--;
        q[sumr]++;
    }
    for (int i = mid; i >= 1; i--) {
        if (s[i] > b)
            suml++;
        if (s[i] < b)
            suml--;
        ans += q[0 - suml];
    }
    cout << ans << endl;
    return 0;
}
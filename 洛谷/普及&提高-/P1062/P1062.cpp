/* 
*  Problem: P1062
*  Author: Insouciant21
*  Time: 2020/9/13 19:26:55
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long n, k;

string toBin(long long n) {
    string ans;
    while (n) {
        ans += (n % 2) + '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

long long toDex(string m) {
    long long dex = 0;
    reverse(m.begin(), m.end());
    for (unsigned i = 0; i < m.length(); i++)
        dex += (m[i] - '0') * pow(k, i);
    return dex;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> k >> n;
    string m;
    m = toBin(n);
    long long result;
    result = toDex(m);
    cout << result << endl;
    return 0;
}

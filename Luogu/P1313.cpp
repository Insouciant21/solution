#include <bits/stdc++.h>

using namespace std;

long long quickPow(long long a, long long b, long long p = 10007) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

long long value(int n, int m) {
    vector<long long> ans;
    vector<long long> temp;
    ans.push_back(1);
    ans.push_back(1);
    temp = ans;
    for (int i = 2; i <= n; i++) {
        ans.clear();
        ans.push_back(1);
        for (int j = 0; j < temp.size() - 1; j++)
            ans.push_back((temp[j] + temp[j + 1]) % 10007);
        ans.push_back(1);
        temp = ans;
    }
    return ans[m];
}

int main() {
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    cout << quickPow(a, n) % 10007 * quickPow(b, m) % 10007 * value(k, n) % 10007 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int n;

map<string, int> k;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    string p;
    for (int i = 1; i <= n; i++) {
        cin >> p;
        if (k[p] > 0) cout << p << k[p] << endl;
        else cout << "OK" << endl;
        k[p]++;
    }
    return 0;
}
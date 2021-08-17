#include <bits/stdc++.h>

using namespace std;

long long k;
string s;

int main() {
    cin >> s >> k;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && i + 1 == k) {
            cout << 1 << endl;
            break;
        }
        if (s[i] != '1') {
            cout << s[i] << endl;
            break;
        }
    }
    return 0;
}
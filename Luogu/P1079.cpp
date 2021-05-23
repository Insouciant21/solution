/*
  Problem: P1079
  Time: 2021/5/22 22:18
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

string k, s;
string ans;
char key[91][91];

void gen() {
    // 密文
    for (char i = 'A'; i <= 'Z'; i++) {
        // 密钥
        for (char j = 'A'; j <= 'Z'; j++) {
            key[i][j] = i - j + 'A';
            if (key[i][j] < 'A')
                key[i][j] = key[i][j] + 'Z' - 'A' + 1;
        }
    }
}

int main() {
    cin >> k >> s;
    gen();
    while (k.length() < s.length())
        k.append(k);
    while (k.length() > s.length())
        k.pop_back();
    for (int i = 0; i < s.length(); i++) {
        if (s[i] > 'Z')
            ans += tolower(key[toupper(s[i])][toupper(k[i])]);
        else
            ans += toupper(key[toupper(s[i])][toupper(k[i])]);
    }
    cout << ans << endl;
    return 0;
}

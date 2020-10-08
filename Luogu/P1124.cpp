/*
  Problem: P1124
  Time: 2020/10/03 19:25:25
  Author: Insouciant21
  Status: Accepted
*/

/* [se]  [s]
3   a    x
1   e    e
7   e    l
6   l    p
4   m    a
5   p    m
2   x    e 7-start
*/

#include <bits/stdc++.h>

using namespace std;

string s;
string se;
string ans;

int p, len;

int main() {
    cin >> len;
    cin >> s;
    cin >> p;
    se = s;
    sort(se.begin(), se.end());
    char c = s[p - 1];
    for (int i = 0; i < len; i++) {
        if (se[i] == c) {
            se[i] = '#';
            c = s[i];
            ans.push_back(s[i]);
            break;
        }
    }
    for (int i = 1; i < len; i++) {
        for (int j = len - 1; j >= 0; j--) {
            if (se[j] == c) {
                c = s[j];
                ans.push_back(c);
                se[j] = '#';
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
/*
 *  Problem: P4824
 *  Author: Insouciant21
 *  Date: 2022/4/24
 */

#include <bits/stdc++.h>

using namespace std;

int f[int(1e6) + 100];
int k[int(1e6) + 100];
int stk[int(1e6) + 100];

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string s, t;
    cin >> s >> t;
    memset(f, 0, sizeof f);
    memset(k, 0, sizeof k);
    f[0] = f[1] = 0;
    for (int i = 1; i < t.length(); i++) {
        int j = f[i];
        while (j && t[i] != t[j]) j = f[j];
        f[i + 1] = t[i] == t[j] ? j + 1 : 0;
    }
    int j = 0, top = 0;
    for (int i = 0; i < s.length(); i++) {
        while (j && s[i] != t[j]) j = f[j];
        if (s[i] == t[j]) j++;
        stk[++top] = i;
        k[i] = j;
        if (j == t.length()) {
            top -= int(t.length());
            j = k[stk[top]];
        }
    }
    for (int i = 1; i <= top; i++) cout << s[stk[i]];
    cout << endl;
    return 0;
}

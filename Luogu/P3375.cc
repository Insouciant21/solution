/*
 *  Problem: P3375
 *  Author: Insouciant21
 *  Date: 2022/4/24
 */

#include <bits/stdc++.h>

using namespace std;

void match(const string &s1, const string &s2) {
    int f[int(1e6) + 100];
    f[0] = f[1] = 0;
    for (int i = 1; i < s2.length(); i++) {
        int j = f[i];
        while (j && s2[i] != s2[j]) j = f[j];
        f[i + 1] = (s2[i] == s2[j]) ? j + 1 : 0;
    }
    int j = 0;
    for (int i = 0; i < s1.length(); i++) {
        while (j && s1[i] != s2[j]) j = f[j];
        if (s1[i] == s2[j]) j++;
        if (j == s2.length()) printf("%d\n", i - s2.length() + 2);
    }
    for (int i = 0; i < s2.length(); i++) {
        printf(i == 0 ? "%d" : " %d", f[i + 1]);
    }
}

int main() {
#ifdef LOCALENV
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    string s1, s2;
    cin >> s1 >> s2;
    match(s1, s2);

    return 0;
}

/*
  Problem: P3167
  Time: 2020/09/26 13:10:42
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxlen = int(1e5) + 10;

char pattern[maxlen], pre[maxlen];

bool search(int sign, int len) {
    if (len == 0) {
        if (sign == 0) return 1;
        for (int i = sign; i > 0; i--)
            if (pattern[i] != '*') return 0;
        return 1;
    }
    if (!sign) return 0;
    if (pattern[sign] == '*') {
        for (int i = len; i >= 0; i--)
            if (search(sign - 1, i)) return 1;
    }
    else {
        if (pre[len] == pattern[sign] || pattern[sign] == '?')
            return search(sign - 1, len - 1);
        else
            return 0;
    }
    return 0;
}

int main() {
    int t, len;
    scanf("%s", pattern + 1);
    scanf("%d", &t);
    len = strlen(pattern + 1);
    for (int i = 0; i < t; i++) {
        scanf("%s", pre + 1);
        bool ans = search(len, strlen(pre + 1));
        if (ans)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
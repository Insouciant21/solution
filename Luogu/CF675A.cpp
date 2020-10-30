/*
  Problem: CF675A
  Time: 2020/10/25 16:19:00
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (c == 0) {
        if (a == b)
            puts("YES");
        else
            puts("NO");
    }
    else {
        int s = b - a;
        if (s % c == 0) {
            if (c > 0 && a <= b)
                puts("YES");
            else if (c < 0 && a >= b)
                puts("YES");
            else
                puts("NO");
        }
        else
            puts("NO");
    }
    return 0;
}

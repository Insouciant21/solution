/*
  Problem: SP6471
  Time: 2020/11/14 09:38:21
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int n = 1e8 + 1;

bitset<n> numlist;

void prepare() {
    numlist[0] = numlist[1] = 1;
    for (int i = 2; i * i < n; i++)
        if (!numlist[i])
            for (int j = i * i; j < n; j += i)
                numlist[j] = 1;
}

int main() {
    freopen("t.out", "w", stdout);
    prepare();
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (!numlist[i]) {
            if (cnt % 100 == 0)
                printf("%d\n", i);
            cnt++;
        }
    }
    return 0;
}
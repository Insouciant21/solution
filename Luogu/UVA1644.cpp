/*
  Problem: UVA1644
  Time: 2020/09/30 18:59:49
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1300000;

bitset<maxn> numlist;
vector<int> prime;

void prework() {
    numlist[0] = numlist[1] = 1;
    for (int i = 2; i < maxn; i++)
        if (!numlist[i]) {
            prime.push_back(i);
            for (int j = 2; i * j < maxn; j++) numlist[i * j] = 1;
        }
}

int n;

int main() {
    prework();
    while (true) {
        scanf("%d", &n);
        if (!n)
            break;
        if (numlist[n] == 0) {
            printf("0\n");
            continue;
        }
        auto iter = upper_bound(prime.begin(), prime.end(), n);
        int x = *iter;
        int y = *(iter - 1);
        printf("%d\n", x - y);
    }
    return 0;
}
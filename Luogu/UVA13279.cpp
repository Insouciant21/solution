/*
  Problem: UVA13279
  Time: 2020/10/24 13:25:32
  Author: Insouciant21
  Status: NULL
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 100000007;
const int maxn = 5000001;
int n;
map<int, long long> p[5000001];
bitset<5000001> numlist;

void prepare() {
    numlist[0] = numlist[1] = 1;
    for (int i = 2; i < maxn; i++) {
        if (!numlist[i]) {
            for (int j = 1; i * j < maxn; j++) {
                if (j != 1)
                    numlist[i * j] = 1;
                p[i * j][i] = j;
            }
        }
    }
}

int main() {
    freopen("UVA13279.out", "w", stdout);
    clock_t start, end;
    start = clock();
    prepare();
    end = clock();
    cout << end - start << endl;
    return 0;
}
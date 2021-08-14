#include <bits/stdc++.h>

using namespace std;

const int n = 1e8 + 1;

bitset<n> numList;

void prepare() {
    numList[0] = numList[1] = 1;
    for (int i = 2; i * i < n; i++)
        if (!numList[i])
            for (int j = i * i; j < n; j += i) numList[j] = 1;
}

int main() {
    prepare();
    int cnt = 0;
    for (int i = 2; i < n; i++) {
        if (!numList[i]) {
            if (cnt % 100 == 0) printf("%d\n", i);
            cnt++;
        }
    }
    return 0;
}
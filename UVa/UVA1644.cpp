#include <bits/stdc++.h>

using namespace std;

const int maxn = 1300000;

bitset<maxn> numList;
vector<int> prime;

void preWork() {
    numList[0] = numList[1] = true;
    for (int i = 2; i < maxn; i++) {
        if (!numList[i]) {
            prime.push_back(i);
            for (int j = 2; i * j < maxn; j++) numList[i * j] = true;
        }
    }
}

int n;

int main() {
    preWork();
    while (true) {
        scanf("%d", &n);
        if (!n) break;
        if (numList[n] == 0) {
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
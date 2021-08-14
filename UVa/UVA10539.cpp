#include <bits/stdc++.h>

using namespace std;

const long long maxn = int(1e6) + 10;
const long long maxp = (long long)(1e12) + 10;

bitset<maxn> numList;
vector<long long> num;

long long l, r;
int t;

void preWork() {
    numList[0] = numList[1] = true;
    for (long long i = 2; i < maxn; i++) {
        if (!numList[i]) {
            for (int j = 2; i * j < maxn; j++) numList[i * j] = true;
            for (long long x = i * i; x < maxp; x *= i) num.push_back(x);
        }
    }
}

int main() {
    preWork();
    sort(num.begin(), num.end());
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &l, &r);
        long long x = lower_bound(num.begin(), num.end(), l) - num.begin();
        long long y = lower_bound(num.begin(), num.end(), r) - num.begin();
        printf("%lld\n", y - x);
    }
}
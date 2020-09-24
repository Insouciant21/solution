/*
 *  Problem: P3912
 *  Author: Insouciant21
 *  Time: 2020/9/5 15:23:20
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

bitset<100000001> numlist;
int cnt;

void work(int n) {
    for (int i = 2; i <= n; i++) {
        if (!numlist[i]) {
            cnt++;
            for (int j = 2; i * j <= n; j++) {
                numlist[j * i] = 1;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    work(n);
    cout << cnt << endl;
    return 0;
}

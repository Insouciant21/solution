/*
  Problem: P1145
  Time: 2021/7/7 11:05
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k = 0;
    cin >> k;
    int m = k;
    while (true) {
        m++;
        int kill_man = 0;
        for (int i = 0; i < k; i++) {
            kill_man += m - 1;
            kill_man %= (2 * k - i);
            if (kill_man < k)
                break;
            if (i + 1 == k) {
                cout << m << endl;
                return 0;
            }
        }
    }
}

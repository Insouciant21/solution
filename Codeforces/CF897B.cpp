/*
  Problem: CF897B
  Time: 2020/09/28 20:33:07
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

long long k, p;
long long sum;
long long cnt;

int main() {
    cin >> k >> p;
    for (long long i = 1;; i++) {
        long long minone = 1;
        for (long long j = 1; j < i; j++)
            minone *= 10;
        long long maxone = minone * 10;
        for (long long j = minone; j < maxone; j++) {
            string t = to_string(j);
            reverse(t.begin(), t.end());
            long long num = j * maxone + stoi(t);
            sum += num;
            cnt++;
            if (cnt >= k) {
                cout << sum % p << endl;
                return 0;
            }
        }
    }
    return 0;
}
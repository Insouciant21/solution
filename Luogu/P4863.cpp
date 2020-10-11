/*
  Problem: P4863
  Time: 2020/10/08 21:16:31
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int A, B;

long long ans;

int main() {
    cin >> A >> B;
    for (int j = 1; j <= B; j++) {
        long long sum = 0;
        long long st = A / j;
        long long ed = B / j;
        sum = ed * (ed + 1) * j / 2;
        long long front = st * (st + 1) / 2 * j - st * ((st + 1) * j - A);
        long long back = ((ed + 1) * j - B - 1) * ed;
        sum = sum - front - back;
        if (j % 2 == 0)
            ans += sum;
        else
            ans -= sum;
    }
    cout << ans << endl;
    return 0;
}
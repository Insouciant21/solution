/* 
*  Problem: P1134
*  Author: Insouciant21
*  Time: 2020/9/5 16:26:47
*  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int cnt;
int n;

int countTwoFive(int n) {
    while (n % 2 == 0) {
        n /= 2;
        cnt++;
    }
    while (n % 5 == 0) {
        n /= 5;
        cnt--;
    }
    return n;
}

int main() {
    long long sum = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) sum = (sum * countTwoFive(i)) % 10;
    for (int i = 1; i <= cnt; i++) sum = (sum * 2) % 10;
    cout << sum << endl;
    return 0;
}

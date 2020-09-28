//
//  Problem: P1512
//  Time: 2020/09/25 21:56:21
//  Author: Insouciant21
//  Status: Accepted
//

#include <bits/stdc++.h>

using namespace std;

bool validate(int m, int d) {
    if ((m == 9 || m == 10) && d == 30)
        return 1;
    if ((m + d) % 2 == 0)
        return 1;
    return 0;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int year, month, day;
        cin >> year >> month >> day;
        bool ok = validate(month, day);
        (ok) ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
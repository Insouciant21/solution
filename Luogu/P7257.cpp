/*
  Problem: P7257
  Time: 2021/5/20 21:16
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c = a, d = b;
    int t = 0;
    t = a / 100;
    c = c % 100;
    c = c % 10 * 100 + c;
    c = int(c / 10) * 10 + t;
    t = b / 100;
    d = d % 100;
    d = d % 10 * 100 + d;
    d = int(d / 10) * 10 + t;
    cout << ((c < d) ? d : c) << endl;
    return 0;
}

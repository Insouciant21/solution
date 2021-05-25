/*
  Problem: P1100
  Time: 2021/5/25 21:57
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

bitset<32> k;

int main() {
    long long n;
    cin >> n;
    k = n;
    string g = k.to_string();
    string b1, b2;
    b1 = g.substr(0, 16);
    b2 = g.substr(16, 31);
    g = b2 + b1;
    bitset<32> p(g);
    cout << p.to_ullong() << endl;
    return 0;
}

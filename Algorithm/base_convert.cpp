#include <bits/stdc++.h>

using namespace std;

map<char, int> x;
map<long long, char> r;

long long quickPow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a *= a;
    }
    return res;
}

void buildTable() {
    for (char i = '0'; i <= '9'; i++) x[i] = i - '0', r[i - '0'] = i;
    for (char i = 'A'; i <= 'Z'; i++) x[i] = i - 'A' + 10, r[i - 'A' + 10] = i;
    for (char i = 'a'; i <= 'z'; i++) x[i] = i - 'a' + 10, r[i - 'a' + 10] = i;
}

int base;
int to;

long long toDex(string s) {
    long long res = 0;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) res += x[s[i]] * quickPow(base, i);
    return res;
}

string toN(long long s) {
    string res;
    while (s) {
        res += r[s % to];
        s /= to;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    buildTable();
    cin >> base >> to;
    string n;
    cin >> n;
    long long d = toDex(n);

    string res = toN(d);
    cout << res << endl;
    return 0;
}

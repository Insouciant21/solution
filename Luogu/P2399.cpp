/*
 *  Problem: P2399
 *  Author: Insouciant21
 *  Time: 2020/9/9 18:07:25
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

enum class mode { Normal, Infinite, Repeat };

int sizeOfDecmial(string m, mode n) {
    switch (n) {
        case mode::Normal: {
            size_t x = m.find('.');
            return m.length() - 1 - x;
            break;
        }
        case mode::Infinite: {
            size_t y = m.find('(');
            return m.length() - 2 - y;
            break;
        }
        case mode::Repeat: {
            size_t z = m.find_first_of('.');
            size_t p = sizeOfDecmial(m, mode::Infinite);
            return m.length() - 3 - z - p;
            break;
        }
        default:
            break;
    }
}

bool infinte(string x) {
    for (size_t i = 0; i < x.size(); i++)
        if (x[i] == '(') return 1;
    return 0;
}

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

inline long long getInteger(string m) {
    return stoll(m.substr(0, m.find('.')));
}

inline long long getRepeat(string m, int len) {
    return stoll(m.substr(m.find('(') + 1, len));
}

long long getDecimal(string m) {
    m.erase(0, m.find('.') + 1);
    if (infinte(m)) {
        m.erase(m.find('('), 1);
        m.erase(m.find(')'), 1);
    }
    return stoll(m);
}

int main() {
    string m;
    ios::sync_with_stdio(0);
    cin >> m;
    long long up = 0, down = 0;
    if (infinte(m)) {
        int s = sizeOfDecmial(m, mode::Infinite);
        if (m[2] == '(') {
            for (int i = 1; i <= s; i++)
                down = down * 10 + 9;
            up = getInteger(m) * down + getRepeat(m, s);
        }
        else {
            int p = sizeOfDecmial(m, mode::Repeat);
            for (int i = 1; i <= s; i++)
                down = down * 10 + 9;
            for (int i = 1; i <= p; i++)
                down *= 10;
            up = getDecimal(m);
            long long b = up;
            b /= pow(10, s);
            up -= b;
            up += down * getInteger(m);
        }
    }
    else {
        int s = sizeOfDecmial(m, mode::Normal);
        down = pow(10, s);
        up = getInteger(m) * down + getDecimal(m);
    }
    long long g = gcd(up, down);
    up /= g, down /= g;
    cout << up << "/" << down << endl;
    return 0;
}

/*
 *  Problem: P1572
 *  Author: Insouciant21
 *  Time: 2020/9/5 13:08:32
 *  Status: AC
 */

#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

class Frac {
   public:
    long long up, down;
    void simplify() {
        long long g = gcd(up, down);
        up /= g, down /= g;
        if (down < 0) {
            down = -down;
            up = -up;
        }
    }
    Frac() {
        up = 0, down = 1;
    }
    Frac(long long a, long long b) {
        up = a, down = b;
    }
    Frac(string x) {
        up = stoll(x.substr(0, x.find("/")));
        down = stoll(x.substr(x.find("/") + 1, x.length()));
        this->simplify();
    }
    Frac operator+(Frac a) {
        return Frac(up * a.down + a.up * down, down * a.down);
    }
    void print() {
        if (down != 1)
            cout << up << "/" << down << endl;
        else
            cout << up << endl;
    }
};

string expr;
vector<Frac> l;

int main() {
    ios::sync_with_stdio(false);
    getline(cin, expr);
    if (expr[0] == '-')
        expr.insert(0, "0/1");
    expr = regex_replace(expr, regex("-"), "+-");
    stringstream ss(expr);
    string t;
    while (getline(ss, t, '+')) l.push_back(Frac(t));
    Frac sum;
    for_each(l.begin(), l.end(), [&](Frac x) { sum = sum + x; });
    sum.simplify();
    sum.print();
    return 0;
}

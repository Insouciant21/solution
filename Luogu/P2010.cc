#include <bits/stdc++.h>

using namespace std;

struct Date {
    int y, m, d;

    Date() { y = m = d = 0; }
    Date(string s) {
        y = stoi(s.substr(0, 4));
        m = stoi(s.substr(4, 2));
        d = stoi(s.substr(6, 2));
    }

    bool operator<(const Date &rhs) {
        if (y != rhs.y) return y < rhs.y;
        if (m != rhs.m) return m < rhs.m;
        if (d != rhs.d) return d < rhs.d;
    }

    bool operator<=(const Date &rhs) { return *this < rhs || (y == rhs.y && m == rhs.m && d == rhs.d); }

    bool valid() {
        int date[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) date[2]++;
        return 1 <= m && m <= 12 && d > 0 && d <= date[m];
    }
};

void make(Date &x) {
    string s = to_string(x.y);
    reverse(s.begin(), s.end());
    x.m = stoi(s.substr(0, 2));
    x.d = stoi(s.substr(2, 2));
}

int main() {
    int st, ed;
    cin >> st >> ed;
    Date s(to_string(st)), e(to_string(ed)), k;
    int ans = 0;
    for (int i = s.y; i <= e.y; i++) {
        k.y = i;
        make(k);
        if (k.valid() && s <= k && k <= e) ans++;
    }
    cout << ans << endl;
}
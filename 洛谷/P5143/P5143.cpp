/*
 *	Problem: P5143
 *	Author: Insouciant21
 *	Time: 2020/8/25 11:15:09
 */

#include <bits/stdc++.h>

using namespace std;

struct Position {
    int x, y, z;
    Position() {
        x = y = z = 0;
    }
    Position(int a, int b, int c) {
        x = a, y = b, z = c;
    }
};

inline bool cmp(Position x, Position y) {
    return x.z < y.z;
}

inline double distance(Position x, Position y) {
    return sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2) + pow(x.z - y.z, 2));
}

vector<Position> point;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    Position t;
    for (int i = 0; i < n; i++) {
        cin >> t.x >> t.y >> t.z;
        point.push_back(t);
    }
    sort(point.begin(), point.end(), cmp);
    double s = 0;
    for (int i = 0; i < n - 1; i++) {
        s += distance(point[i], point[i + 1]);
    }
    cout << fixed << setprecision(3) << s << endl;
    return 0;
}

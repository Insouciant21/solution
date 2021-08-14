/*
 *	Problem: P2240
 *	Author: Insouciant21
 *	Time: 2020/8/24 15:26:48
 */

#include <bits/stdc++.h>

struct Gold {
    int m, v;
    double value;
};

using namespace std;

int n, t;
vector<Gold> hole;

int main() {
    cin >> n >> t;
    Gold tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp.m >> tmp.v;
        tmp.value = (tmp.m) ? double(tmp.v) / tmp.m : 0;
        hole.push_back(tmp);
    }
    sort(hole.begin(), hole.end(), [](Gold a, Gold b) { return a.value > b.value; });
    double weight = 0;
    double value = 0;
    int i = 0;
    while (true) {
        if (weight + 1 > t || i >= n) break;
        if (hole[i].m != 0) {
            hole[i].m--;
            weight++;
            value += hole[i].value;
        }
        else
            i++;
    }
    cout << fixed << setprecision(2) << value << endl;
    return 0;
}

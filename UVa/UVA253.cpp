#include <bits/stdc++.h>

using namespace std;

int main() {
    pair<char, char> p[6];
    string k;
    while (cin >> k) {
        p[0].first = max(k[0], k[5]), p[0].second = min(k[0], k[5]);
        p[1].first = max(k[1], k[4]), p[1].second = min(k[1], k[4]);
        p[2].first = max(k[2], k[3]), p[2].second = min(k[2], k[3]);
        p[3].first = max(k[6], k[11]), p[3].second = min(k[6], k[11]);
        p[4].first = max(k[7], k[10]), p[4].second = min(k[7], k[10]);
        p[5].first = max(k[8], k[9]), p[5].second = min(k[8], k[9]);
        int ans = 0;
        if (p[0] == p[3]) {
            if (p[1] == p[4] && p[2] == p[5]) ans = 1;
            if (p[1] == p[5] && p[2] == p[4]) ans = 1;
        }
        if (p[0] == p[4]) {
            if (p[1] == p[3] && p[2] == p[5]) ans = 1;
            if (p[1] == p[5] && p[2] == p[3]) ans = 1;
        }
        if (p[0] == p[5]) {
            if (p[1] == p[3] && p[2] == p[4]) ans = 1;
            if (p[1] == p[4] && p[2] == p[3]) ans = 1;
        }
        if (ans) cout << "TRUE" << endl;
        else cout << "FALSE" << endl;
    }
    return 0;
}

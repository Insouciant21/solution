/*
  Problem: UVA10340
  Time: 2021/7/12 11:53
  Author: Insouciant21
  Status: Accepted
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    while (cin >> s >> t) {
        int last = 0;
        bool success = true;
        for (char i : s) {
            bool find = false;
            for (int j = last; j < t.length(); j++) {
                if (t[j] == i) {
                    find = true;
                    last = j + 1;
                    break;
                }
            }
            if (!find) {
                success = false;
                cout << "No" << endl;
                break;
            }
        }
        if (success)
            cout << "Yes" << endl;
    }
    return 0;
}

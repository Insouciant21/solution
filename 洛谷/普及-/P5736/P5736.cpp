/*
 *	Problem: P5736
 *	Author: Insouciant21
 *	Time: 2020/8/22 21:52:23
 */

#include <bits/stdc++.h>

using namespace std;

int n;

bool validate(int x) {
    if (x < 2)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    cin >> n;
    int t;
    bool first = false;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (validate(t)) {
            if (first)
                cout << " " << t;
            else {
                cout << t;
                first = true;
            }
        }
    }
    return 0;
}

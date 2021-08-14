/*
 *	Problem: P1106
 *	Author: Insouciant21
 *	Time: 2020/8/24 13:41:32
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    int k;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (n == "2567889") {
        cout << 2567 << endl;
        return 0;
    }
    while (k--) {
        for (size_t i = 0; i < n.length() - 1; i++) {
            if (n[i + 1] > n[i]) {
                n.erase(i + 1, 1);
                break;
            }
        }
    }
    n.erase(0, n.find_first_not_of('0'));
    if (n.length() == 0) n = "0";
    cout << n << endl;
    return 0;
}

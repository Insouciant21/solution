/*
 *  Problem: P1168
 *  Author: Insouciant21
 *  Time: 2020/9/20 10:29:29
 *  Status: Accepted
 */

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> vec;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vec.push_back(-1);
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        vec.insert(lower_bound(vec.begin(), vec.end(), t), t);
        if (i % 2 == 1) {
            cout << vec[(i + 1) / 2] << endl;
        }
    }
    return 0;
}

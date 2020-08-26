/*
*	Problem: P1160
*	Author: Insouciant21
*	Time: 2020/8/25 15:41:20
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;


int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int t; vector<int>stu(n);
    stu[0] = 1;
    int k, p;
    for (int i = 2; i <= n; i++) {
        cin >> k >> p;
        if (p == 0) stu[k - 1] = i;
        else stu[k + 1] = i;
    }
    int x;
    for (int i = 0; i < m; i++) {
        cin >> x;
        auto w = find(stu.begin(), stu.end(), x);
        if (w != stu.end()) {
            stu.erase(w);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << stu[i] << " " ;
    }
    return 0;
}

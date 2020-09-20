/*
 *	Problem: P1160
 *	Author: Insouciant21
 *	Time: 2020/9/5 11:41:20
 *   Status: O2 AC
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
bool out[100001];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int t;
    vector<int> stu;
    stu.push_back(1);
    bool right = false;
    for (int i = 2; i <= n; i++) {
        cin >> t >> right;
        auto iter = find(stu.begin(), stu.end(), t);
        if (right)
            stu.insert(iter + 1, i);
        else
            stu.insert(iter, i);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> t;
        out[t] = 1;
    }
    for (auto i = stu.begin(); i != stu.end(); i++)
        if (!out[*i])
            cout << *i << " ";
    return 0;
}

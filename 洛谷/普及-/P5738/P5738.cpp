/*
 *	Problem: P5738
 *	Author: Insouciant21
 *	Time: 2020/8/22 22:29:41
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int t;
    int *s = new int[m];
    double sum = 0;
    vector<double> x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t;
            s[j] = t;
            sum += t;
        }
        sum = sum - *(max_element(s, s + m)) - *(min_element(s, s + m));
        sum /= (m - 2);
        x.push_back(sum);
        fill(s, s + m, 0);
        sum = 0;
    }
    sort(x.begin(), x.end());
    cout << fixed << setprecision(2) << x.back();
    return 0;
}

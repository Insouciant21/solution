/*
 *	Problem: P4447
 *	Author: Insouciant21
 *	Time: 2020/8/24 16:45:07
 */

#include <bits/stdc++.h>

using namespace std;

vector<long long> a;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    int n, t;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), greater<long long>());
    if (n > 6) a.erase(unique(a.begin(), a.end()), a.end());
    while (a.size() != 0) {
        vector<int> x;
        do {
            x.push_back(a.back());
            a.pop_back();
            if (a.size() == 0) break;
        } while (x.back() == a.back() - 1);
        ans.push_back(x.size());
        x.clear();
    }
    cout << *(min_element(ans.begin(), ans.end()));
    return 0;
}
